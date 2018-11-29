/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hhu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 23:29:23 by tduval            #+#    #+#             */
/*   Updated: 2018/11/29 02:34:36 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	split3(int s, t_flags elem)
{
	int	i;

	i = 0;
	if (elem.accuracy != -1)
	{
		if (ft_strchr(elem.options, '+'))
		{
			ft_putchar('+');
			i++;
		}
		while (elem.accuracy-- > s )
		{
			ft_putchar('0');
			i++;
		}
	}
	return (i);
}

static int	split2(unsigned char n, int s, int u, t_flags elem)
{
	int	i;

	i = split3(s, elem);
	if (n || (!n && elem.accuracy != 0))
		print_lllu((unsigned long long)n);
	if (ft_strchr(elem.options, '-') && elem.width)
	{
		while (elem.width > s + ((ft_strchr(elem.options, ' ') ||
				ft_strchr(elem.options, '+')) ? 1 : 0) + (u != -1 ? u - s : 0))
		{
			ft_putchar(' ');
			elem.width--;
			i++;
		}
	}
	return (i);
}

static int	print_padding(unsigned char n, int s, t_flags elem)
{
	int	i;
	int	u;

	i = 0;
	if (!ft_strchr(elem.options, '-') && elem.width)
	{
		while (elem.width > s + ((((ft_strchr(elem.options, ' ') ||
				ft_strchr(elem.options, '+')) && n > 0) ? 1 : 0) +
				(elem.accuracy != -1 ? elem.accuracy - s : 0)))
		{
			ft_putchar(ft_strchr(elem.options, '0') &&
						elem.accuracy > s ? '0' : ' ');
			elem.width--;
			i++;
		}
	}
	u = elem.accuracy;
	return (i + split2(n, s, u, elem));
}

int		print_hhu(va_list ap, t_flags elem)
{
	unsigned char	n;
	unsigned char	cp;
	int				i;

	i = 1;
	n = (unsigned char)va_arg(ap, int);
	cp = n;
	while (cp > 9)
	{
		cp /= 10;
		i++;
	}
	return (n == 0 && elem.accuracy == 0 ?
		print_padding(n, 0, elem) : i + print_padding(n, i, elem));
}
