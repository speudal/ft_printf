/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hho.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 23:12:56 by tduval            #+#    #+#             */
/*   Updated: 2018/11/27 18:02:14 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		print_hho(va_list ap, t_flags elem)
{
	unsigned char	n;
	int				i;

	i = 1;
	if (ft_strchr(elem.options, '#'))
	{
		ft_putchar('0');
		i++;
	}
	n = (unsigned char)va_arg(ap, int);
	print_lllo((long long)n);
	while (n > 7)
	{
		n /= 8;
		i++;
	}
	return (i);
}
