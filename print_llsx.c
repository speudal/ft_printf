/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_llsx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 10:26:22 by tduval            #+#    #+#             */
/*   Updated: 2018/11/30 03:17:44 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libftprintf.h"

void	print_lllsx(unsigned long long n)
{
	if (n > 15)
		print_lllsx(n / 16);
	ft_putchar(n % 16 > 9 ? n % 16 + 'a' - 10 : n % 16 + '0');
}

static int split3(unsigned long long n, int s, t_flags elem)
{
	int i;

	i = 0;
	if (elem.accuracy != -1)
	{
		if (ft_strchr(elem.options, '#') && n)
			ft_putstr("0x");
		while (elem.accuracy-- > s - (ft_strchr(elem.options, '#') && n ? 2 : 0))
		{
			ft_putchar('0');
			i++;
		}
	}
	return (i);
}

static int split2(unsigned long long n, int s, int u, t_flags elem)
{
	int i;

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

static int print_padding(unsigned long long n, int s, t_flags elem)
{
	int i;
	int	w;
	int u;

	i = 0;
	w = elem.width;
	if (ft_strchr(elem.options, '#') && elem.accuracy == -1 && (elem.width < s || ft_strchr(elem.options, '0')) && n)
		ft_putstr("0x");
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
		ft_putstr("0x");
	return (i + split2(n, s, u, elem));
}

int		print_llsx(va_list ap, t_flags elem)
{
	unsigned long long	n;
	unsigned long long	cp;
	int					i;

	i = 1;
	n = va_arg(ap, unsigned long long);
	cp = n;
	if (ft_strchr(elem.options, '#') && (elem.width < 1 || n))
		i += 2;
	if (ft_strchr(elem.options, '#') && !n && elem.width < 1 && elem.accuracy == -1)
		return ((int)write(1, "0", 1));
	while (cp > 15)
	{
		cp /= 16;
		i++;
	}
	return (n == 0 && elem.accuracy == 0 ? print_padding(n, 0, elem) : i + print_padding(n, i, elem));
}
