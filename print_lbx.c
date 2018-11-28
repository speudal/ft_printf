/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lbx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 10:48:07 by tduval            #+#    #+#             */
/*   Updated: 2018/11/27 18:05:47 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		print_lbx(va_list ap, t_flags elem)
{
	unsigned long	n;
	int				i;

	i = 1;
	if (ft_strchr(elem.options, '#'))
	{
		ft_putstr("0X");
		i += 2;
	}
	n = va_arg(ap, unsigned long);
	print_lllbx((unsigned long long)n);
	while (n > 15)
	{
		n /= 16;
		i++;
	}
	return (i);
}
