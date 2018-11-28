/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 10:34:00 by tduval            #+#    #+#             */
/*   Updated: 2018/11/28 14:30:36 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	split1(unsigned int n, t_flags elem, int *j)
{
	int	i;

	i = 0;
	if (ft_strchr(elem.options, '#') && elem.accuracy == -1)
	{
		ft_putstr("0x");
		*j = 1;
	}
	return (i);
}

static int split3(unsigned int n, int s, t_flags elem)
{
	int i;

	i = 0;
	if (elem.accuracy != -1)
	{
		if (ft_strchr(elem.options, '#'))
			ft_putstr("0x");
		while (elem.accuracy-- > s)
		{
			ft_putchar('0');
			i++;
		}
	}
	return (i);
}

static int split2(unsigned int n, int s, int u, t_flags elem)
{
	int i;
	int c;

	i = split3(n, s, elem);
	if (n || (!n && elem.accuracy != 0))
		print_lllsx((unsigned long long)n);
	if (ft_strchr(elem.options, '-') && elem.width)
	{
		while (elem.width > s + ((ft_strchr(elem.options, ' ') || ft_strchr(elem.options, '+')) ? 1 : 0) + (u != -1 ? u - s : 0))
		{
			ft_putchar(' ');
			elem.width--;
			i++;
		}
	}
	return (i);
}

static int print_padding(unsigned int n, int s, t_flags elem)
{
	int i;
	int u;
	int j;

	i = split1(n, elem, &j);
	if (!ft_strchr(elem.options, '-') && elem.width)
	{
		while (elem.width > s + ((((ft_strchr(elem.options, ' ') ||
									ft_strchr(elem.options, '+')) &&
								   n > 0)
									  ? 1
									  : 0) +
								 (elem.accuracy != -1 ? elem.accuracy - s : 0)))
		{
			ft_putchar(ft_strchr(elem.options, '0') &&
							   elem.accuracy == -1
						   ? '0'
						   : ' ');
			elem.width--;
			i++;
		}
	}
	u = elem.accuracy;
	return (i + split2(n, s, u, elem));
}

int		print_sx(va_list ap, t_flags elem)
{
	unsigned int	n;
	unsigned int	cp;
	int				i;

	i = 1;
	n = va_arg(ap, unsigned int);
	cp = n;
	if (ft_strchr(elem.options, '#') && n)
		i += 2;
	while (cp > 15)
	{
		cp /= 16;
		i++;
	}
	return (n == 0 && elem.accuracy == 0 ? print_padding(n, i, elem) : i + print_padding(n, i, elem));
}
