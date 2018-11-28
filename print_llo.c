/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_llo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 23:08:31 by tduval            #+#    #+#             */
/*   Updated: 2018/11/27 18:02:44 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_lllo(unsigned long long n)
{
	if (n > 7)
		print_lllo(n / 8);
	ft_putchar(n % 8 + 48);
}

int		print_llo(va_list ap, t_flags elem)
{
	unsigned long long	n;
	int					i;

	i = 1;
	if (ft_strchr(elem.options, '#'))
	{
		ft_putchar('0');
		i++;
	}
	n = va_arg(ap, unsigned long long);
	print_llld(n);
	while (n > 7)
	{
		n /= 8;
		i++;
	}
	return (i);
}
