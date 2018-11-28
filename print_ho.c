/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ho.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 23:10:54 by tduval            #+#    #+#             */
/*   Updated: 2018/11/27 18:01:54 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		print_ho(va_list ap, t_flags elem)
{
	unsigned short	n;
	int				i;

	i = 1;
	if (ft_strchr(elem.options, '#'))
	{
		ft_putchar('0');
		i++;
	}
	n = (unsigned short)va_arg(ap, unsigned int);
	print_lllo((long long)n);
	while (n > 7)
	{
		n /= 8;
		i++;
	}
	return (i);
}
