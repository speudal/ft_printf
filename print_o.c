/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 22:47:48 by tduval            #+#    #+#             */
/*   Updated: 2018/11/29 02:37:20 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libftprintf.h"

static int split3(unsigned int n, int s, t_flags elem)
{
	int i;

	i = 0;
	if (elem.accuracy != -1)
	{
		if (ft_strchr(elem.options, '#') && n)
			ft_putchar('0');
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

	i = split3(n, s, elem);
	if (n || (!n && elem.accuracy != 0) || ft_strchr(elem.options, '#'))
		print_lllo((unsigned long long)n);
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
	int w;
	int u;

	i = 0;
	w = elem.width;
	if (ft_strchr(elem.options, '#') && elem.accuracy == -1 && (elem.width < s || ft_strchr(elem.options, '0')) && n)
		ft_putchar('0');
	if (!ft_strchr(elem.options, '-') && elem.width)
	{
		while (elem.width > s + (elem.accuracy > s ? elem.accuracy - s : 0))
		{
			ft_putchar(ft_strchr(elem.options, '0') && elem.accuracy == -1 ? '0' : ' ');
			elem.width--;
			i++;
		}
	}
	u = elem.accuracy;
	if (ft_strchr(elem.options, '#') && elem.accuracy == -1 && n && w > s && !ft_strchr(elem.options, '0'))
		ft_putchar('0');
	return (i + split2(n, s, u, elem));
}

int print_o(va_list ap, t_flags elem)
{
	unsigned int n;
	unsigned int cp;
	int i;

	i = 1;
	n = va_arg(ap, unsigned int);
	if (ft_strchr(elem.options, '#'))
		i++;
	if (ft_strchr(elem.options, '#') && !n)
		return ((int)write(1, "0", 1));
	cp = n;
	while (cp > 7)
	{
		cp /= 8;
		i++;
	}
	return (n == 0 && elem.accuracy == 0 ? print_padding(n, 0, elem) : i + print_padding(n, i, elem));
}
