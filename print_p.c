/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 21:56:10 by tduval            #+#    #+#             */
/*   Updated: 2018/11/29 03:42:44 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "libftprintf.h"

static void	print(size_t n)
{
	if (n > 15)
		print(n / 16);
	ft_putchar(n % 16 > 9 ? n % 16 + 'a' - 10 : n % 16 + '0');
}

int			print_p(va_list ap, t_flags elem)
{
	size_t		n;
	size_t		cp;
	int			i;

	i = 3;
	n = va_arg(ap, size_t);
	cp = n;
	if (!n && !elem.accuracy)
		return ((int)(write(1, "0x", 2)));
	while (cp > 15)
	{
		cp /= 16;
		i++;
	}
	while (elem.width > i && !(ft_strchr(elem.options, '-')))
	{
		ft_putchar(' ');
		i++;
	}
	ft_putstr("0x");
	while (elem.accuracy > i - 2)
	{
		ft_putchar('0');
		i++;
	}
	print(n);
	while (elem.width > i && ft_strchr(elem.options, '-'))
	{
		ft_putchar(' ');
		i++;
	}
	return (i);
}
