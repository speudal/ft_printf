/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lld.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 22:27:53 by tduval            #+#    #+#             */
/*   Updated: 2018/11/28 02:22:12 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libftprintf.h"

void print_llld(long long n)
{
	if (n == -9223372036854775807 - 1)
	{
		write(1, "9223372036854775808", 19);
		return ;
	}
	if (n < 0)
		n *= -1;
	if (n > 9)
		print_llld(n / 10);
	ft_putchar(n % 10 + 48);
}

static int split1(long long n, t_flags elem, int *j)
{
	int i;

	i = 0;
	if (n > -1)
	{
		if (ft_strchr(elem.options, '+') && n > -1)
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
	else if (ft_strchr(elem.options, '0') && n < 0)
		ft_putchar('-');
	return (i);
}

static int split2(long long n, int s, int u, t_flags elem)
{
	int i;

	i = 0;
	if (elem.accuracy != -1)
	{
		while (elem.accuracy-- > s)
		{
			ft_putchar('0');
			i++;
		}
	}
	if (!ft_strchr(elem.options, '0') && n < 0)
		ft_putchar('-');
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

static int print_padding(long long n, int s, t_flags elem)
{
	int i;
	int u;
	int j;

	i = split1(n, elem, &j);
	if (!ft_strchr(elem.options, '-') && elem.width)
	{
		while (elem.width > s + (((ft_strchr(elem.options, ' ') || ft_strchr(elem.options, '+')) && n > 0) ? 1 : 0) +
								(elem.accuracy != -1 ? elem.accuracy - s : 0))
		{
			ft_putchar(ft_strchr(elem.options, '0') &&
							   elem.accuracy == -1
						   ? '0'
						   : ' ');
			elem.width--;
			i++;
		}
	}
	j = 0;
	u = elem.accuracy;
	return (i + split2(n, s, u, elem));
}

int print_lld(va_list ap, t_flags elem)
{
	long long n;
	long long cp;
	int i;

	i = 1;
	n = va_arg(ap, long long);
	cp = n;
	if (n == -9223372036854775807 - 1)
		i = 20;
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
	return (i += print_padding(n, i, elem));
}
