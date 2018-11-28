/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 12:40:53 by tduval            #+#    #+#             */
/*   Updated: 2018/11/28 14:20:44 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libftprintf.h"

int	(*g_array_print[52])(va_list, t_flags) = {
	print_c,
	0,
	0,
	0,
	0,
	print_s,
	0,
	0,
	0,
	0,
	print_p,
	0,
	0,
	0,
	0,
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
	print_per,
	0,
	0,
	0,
	0,
	0,
	0
};

int		dispatcher(t_flags elem, va_list ap)
{
	int		i;
	char	*flags;

	i = 0;
	flags = "cspdiouxX%";
	while (flags[i] != elem.conv && flags[i])
		i++;
	i *= 5;
	if (!(ft_strcmp(elem.size, "h")) && elem.conv != '%')
		i++;
	if (!(ft_strcmp(elem.size, "hh")) && elem.conv != '%')
		i += 2;
	if (!(ft_strcmp(elem.size, "l")) && elem.conv != '%')
		i += 3;
	if (!(ft_strcmp(elem.size, "ll")) && elem.conv != '%')
		i += 4;
	return (i != 10 ? g_array_print[i](ap, elem) : 0);
}

int			ft_printf(const char *format, ...)
{
	t_flags	*list;
	va_list	ap;
	int		res;
	int		ct;
	int		u;
	int		i;

	u = 0;
	res = 0;
	ct = 0;
	i = 0;
	va_start(ap, format);
	if (!(list = get_flags(format)))
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
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
				while (!ft_strchr("cdfiopsuxX", format[i]) && format[i])
					i++;
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
	free(list);
	va_end(ap);
	return (res);
}
