/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 21:40:47 by tduval            #+#    #+#             */
/*   Updated: 2018/11/28 01:30:29 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "libftprintf.h"

int		print_c(va_list ap, t_flags elem)
{
	char	c;
	int		i;
	int		j;

	i = 0;
	while (i < elem.width - 1 && !ft_strchr(elem.options, '-'))
	{
		ft_putchar(' ');
		i++;
	}
	c = (char)(va_arg(ap, int));
	i += (int)write(1, &c, 1);
	j = 0;
	while (j < elem.width - 1 && ft_strchr(elem.options, '-'))
	{
		ft_putchar(' ');
		i++;
		j++;
	}
	return (i);
}
