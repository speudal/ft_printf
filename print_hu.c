/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 23:27:01 by tduval            #+#    #+#             */
/*   Updated: 2018/11/28 02:20:15 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	split3(unsigned short n, int s, t_flags elem)
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

static int	split2(unsigned short n, int s, int u, t_flags elem)
{
	int	i;
	int	c;

	i = split3(n, s, elem);
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

static int	print_padding(unsigned short n, int s, t_flags elem)
{
	int	i;
	int	u;
	int	j;

	i = 0;
	if (!ft_strchr(elem.options, '-') && elem.width)
	{
		while (elem.width > s + ((((ft_strchr(elem.options, ' ') ||
				ft_strchr(elem.options, '+')) && n > 0) ? 1 : 0) +
				(elem.accuracy != -1 ? elem.accuracy - s : 0)))
		{
			ft_putchar(ft_strchr(elem.options, '0') &&
						elem.accuracy == -1 ? '0' : ' ');
			elem.width--;
			i++;
		}
	}
	u = elem.accuracy;
	return (i + split2(n, s, u, elem));
}

int		print_hu(va_list ap, t_flags elem)
{
	unsigned short	n;
	unsigned short	cp;
	int				i;

	i = 1;
	n = (unsigned short)va_arg(ap, unsigned int);
	cp = n;
	while (cp > 9)
	{
		cp /= 10;
		i++;
	}
	return (n == 0 && elem.accuracy == 0 ?
		print_padding(n, i, elem) : i + print_padding(n, i, elem));
	return (i);
}
