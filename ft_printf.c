/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 12:40:53 by tduval            #+#    #+#             */
/*   Updated: 2018/11/30 04:20:23 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "libftprintf.h"

int	(*g_array_print[80])(va_list, t_flags) = {
	print_c,
	print_c,
	print_c,
	print_c,
	print_c,
	print_s,
	print_s,
	print_s,
	print_s,
	print_s,
	print_p,
	print_p,
	print_p,
	print_p,
	print_p,
	print_d,
	print_hd,
	print_hhd,
	print_ld,
	print_lld,
	print_i,
	print_hi,
	print_hhi,
	print_li,
	print_lli,
	print_o,
	print_ho,
	print_hho,
	print_lo,
	print_llo,
	print_u,
	print_hu,
	print_hhu,
	print_lu,
	print_llu,
	print_sx,
	print_hsx,
	print_hhsx,
	print_lsx,
	print_llsx,
	print_bx,
	print_hbx,
	print_hhbx,
	print_lbx,
	print_llbx,
	print_ld,
	print_ld,
	print_ld,
	print_ld,
	print_ld,
	print_lo,
	print_lo,
	print_lo,
	print_lo,
	print_lo,
	print_lu,
	print_lu,
	print_lu,
	print_lu,
	print_lu,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0
};

static int	check_sizes(char *str, char conv)
{
	return (!ft_strchr("cspdiouxXDOU%", conv) || (ft_strcmp(str, "h") && ft_strcmp(str, "hh") && ft_strcmp(str, "l") && ft_strcmp(str, "ll") && ft_strcmp(str, "") && ft_strcmp(str, "z") && ft_strcmp(str, "j")));
}

int		dispatcher(t_flags elem, va_list ap)
{
	int		i;
	char	*flags;

	i = 0;
	if (!elem.conv)
		return (0);
	flags = "cspdiouxXDOU";
	while (flags[i] != elem.conv && flags[i])
		i++;
	i %= 13;
	i *= 5;
	if (check_sizes(elem.size, elem.conv))
		return (0);
	if (!(ft_strcmp(elem.size, "h")) && elem.conv != '%')
		i++;
	if (!(ft_strcmp(elem.size, "hh")) && elem.conv != '%')
		i += 2;
	if (!(ft_strcmp(elem.size, "l")) && elem.conv != '%')
		i += 3;
	if ((!(ft_strcmp(elem.size, "ll")) || !(ft_strcmp(elem.size, "j"))) && elem.conv != '%')
		i += 4;
	if ((!(ft_strcmp(elem.size, "z")) && (elem.conv == 'd' || elem.conv == 'i')))
		return (print_lld(ap, elem));
	if ((!(ft_strcmp(elem.size, "z")) && elem.conv == 'u'))
		return (print_llu(ap, elem));
	if ((!(ft_strcmp(elem.size, "z")) && elem.conv == 'o'))
		return (print_llo(ap, elem));
	if ((!(ft_strcmp(elem.size, "z")) && elem.conv == 'x'))
		return (print_llsx(ap, elem));
	if ((!(ft_strcmp(elem.size, "z")) && elem.conv == 'X'))
		return (print_llbx(ap, elem));
	if (elem.conv == '%')
		return (print_per(elem));
	return (g_array_print[i] ? g_array_print[i](ap, elem) : 0);
}

static void	free_whole(t_flags *list, int ct)
{
	int		i;

	i = 0;
	while (i < ct)
	{
		if (list[i].options)
			free(list[i].options);
		if (list[i].size)
			free(list[i].size);
		i++;
	}
}

static int	sub2(const char *format)
{
	if (format[0] && format[0] == '%')
		return (0);
	else
		return ((int)write(1, format, ft_strlen(format)));
}
#include <stdio.h>

int			ft_printf(const char *format, ...)
{
	t_flags	*list;
	va_list	ap;
	int		res;
	int		ct;
	int		i;

	list = 0;
	res = 0;
	ct = 0;
	i = 0;
	if (ft_strlen(format) < 2)
		return (sub2(format));
	va_start(ap, format);
	if (!(list = get_flags(format)))
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (!check_sizes(list[ct].size, list[ct].conv))
			{
				if (list[ct].conv == '%')
				{
					res += dispatcher(list[ct], ap);
					i++;
					while (format[i] != '%')
						i++;
				}
				else
				{
					res += dispatcher(list[ct], ap);
					while (!ft_strchr("cdfiopsuxXDOU", format[i]) && format[i])
						i++;
				}
			}
			i++;
			ct++;
		}
		else
		{
			res++;
			ft_putchar(format[i]);
			i++;
		}
	}
	free_whole(list, ct);
	if (list)
		free(list);
	va_end(ap);
	return (res);
}
