/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lld.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 22:27:53 by tduval            #+#    #+#             */
/*   Updated: 2018/11/30 23:17:49 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "libftprintf.h"

void	print_llld(long long n)
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

int		print_lld(va_list ap, t_flags elem)
{
	long long	n;
	long long	cp;
	int			i;

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
	return (n == 0 && elem.accuracy == 0 ?
	padding_d(n, 0, elem) : i +
	padding_d(n, i, elem));
}
