/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 22:37:35 by tduval            #+#    #+#             */
/*   Updated: 2018/11/29 03:53:05 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int split1(short int n, t_flags elem, int *j)
{
	int i;

	i = 0;
	if (n > -1)
	{
		if (ft_strchr(elem.options, '+') && elem.accuracy == -1 && n > -1)
		{
			ft_putchar('+');
			*j = 1;
			i++;
		}
		else if (ft_strchr(elem.options, ' ') && n > -1)
		{
			ft_putchar(' ');
			*j = 1;
			i++;
		}
	}
	else if (elem.accuracy == -1 && ft_strchr(elem.options, '0') && n < 0)
		ft_putchar('-');
	return (i);
}

static int split3(short int n, int s, t_flags elem)
{
	int i;

	i = 0;
	if (elem.accuracy != -1)
	{
		if (n < 0)
			ft_putchar('-');
		else if (ft_strchr(elem.options, '+'))
		{
			ft_putchar('+');
			i++;
		}
		while (elem.accuracy-- > s - (n < 0 ? 1 : 0))
		{
			ft_putchar('0');
			i++;
		}
	}
	return (i);
}

static int split2(short int n, int s, int u, t_flags elem)
{
	int i;

	i = split3(n, s, elem);
	if (!ft_strchr(elem.options, '0') && elem.accuracy == -1 && n < 0)
		ft_putchar('-');
	if (n || (!n && elem.accuracy != 0))
		print_llld((long long)n);
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

static int print_padding(short int n, int s, t_flags elem)
{
	int i;
	int u;
	int j;

	i = split1(n, elem, &j);
	if (!ft_strchr(elem.options, '-') && elem.width)
	{
		while (elem.width > s + ((((ft_strchr(elem.options, ' ') ||
									ft_strchr(elem.options, '+')) &&
								   n > -1) || (n < 0 && elem.accuracy > s - 1) ? 1 : 0) +
								 (elem.accuracy > s ? elem.accuracy - s : 0)))
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

int print_hd(va_list ap, t_flags elem)
{
	int i;
	short n;
	short cp;

	i = 1;
	n = (short)va_arg(ap, int);
	cp = n;
	if (n == -32768)
		i = 6;
	else
	{
		if (cp < 0)
		{
			cp *= -1;
			i++;
		}
		while (cp > 9)
		{
			cp /= 10;
			i++;
		}
	}
	return (n == 0 && elem.accuracy == 0 ? print_padding(n, 0, elem) : i + print_padding(n, i, elem));
}
