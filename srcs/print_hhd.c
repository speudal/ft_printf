/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hhd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 22:40:42 by tduval            #+#    #+#             */
/*   Updated: 2018/11/30 21:36:34 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		print_hhd(va_list ap, t_flags elem)
{
	char	n;
	char	cp;
	int		i;

	i = 1;
	n = (char)va_arg(ap, int);
	cp = n;
	if (n == -128)
		i = 4;
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
