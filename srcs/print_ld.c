/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ld.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 22:35:58 by tduval            #+#    #+#             */
/*   Updated: 2018/11/30 23:16:56 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

int		print_ld(va_list ap, t_flags elem)
{
	long	n;
	long	cp;
	int		i;

	i = 1;
	n = va_arg(ap, long);
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
	padding_d((long long)n, 0, elem) : i +
	padding_d((long long)n, i, elem));
}
