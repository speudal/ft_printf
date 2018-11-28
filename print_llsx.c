/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_llsx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 10:26:22 by tduval            #+#    #+#             */
/*   Updated: 2018/11/27 18:04:39 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_lllsx(unsigned long long n)
{
	if (n > 15)
		print_lllsx(n / 16);
	ft_putchar(n % 16 > 9 ? n % 16 + 'a' - 10 : n % 16 + '0');
}

int		print_llsx(va_list ap, t_flags elem)
{
	unsigned long long	n;
	int					i;

	i = 1;
	if (ft_strchr(elem.options, '#'))
	{
		ft_putstr("0x");
		i += 2;
	}
	n = va_arg(ap, unsigned long long);
	print_lllsx(n);
	while (n > 15)
	{
		n /= 16;
		i++;
	}
	return (i);
}
