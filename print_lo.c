/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 23:14:51 by tduval            #+#    #+#             */
/*   Updated: 2018/11/27 18:02:34 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		print_lo(va_list ap, t_flags elem)
{
	int	i;
	int	n;

	i = 1;
	if (ft_strchr(elem.options, '#'))
	{
		ft_putchar('0');
		i++;
	}
	n = va_arg(ap, unsigned long);
	print_lllo((long long)n);
	while (n > 7)
	{
		n /= 8;
		i++;
	}
	return (i);
}
