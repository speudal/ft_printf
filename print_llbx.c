/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_llbx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 10:49:38 by tduval            #+#    #+#             */
/*   Updated: 2018/11/27 18:06:00 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_lllbx(unsigned long long n)
{
	if (n > 15)
		print_lllbx(n / 16);
	ft_putchar(n % 16 > 9 ? n % 16 + 'A' - 10 : n % 16 + '0');
}

int		print_llbx(va_list ap, t_flags elem)
{
	unsigned long long	n;
	int					i;

	i = 1;
	if (ft_strchr(elem.options, '#'))
	{
		ft_putstr("0X");
		i += 2;
	}
	n = va_arg(ap, unsigned long long);
	print_lllbx(n);
	while (n > 15)
	{
		n /= 16;
		i++;
	}
	return (i);
}
