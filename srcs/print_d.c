/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 22:30:13 by tduval            #+#    #+#             */
/*   Updated: 2018/12/01 00:59:37 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		print_d(va_list ap, t_flags elem)
{
	int	i;
	int	n;
	int	cp;

	i = 1;
	n = va_arg(ap, int);
	cp = n;
	if (n == -2147483648)
		i = 11;
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
