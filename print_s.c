/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 21:45:30 by tduval            #+#    #+#             */
/*   Updated: 2018/11/28 15:28:36 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libftprintf.h"

int		print_s(va_list ap, t_flags elem)
{
	char		*s;
	int			i;
	int			j;

	i = 0;
	j = 0;
	s = va_arg(ap, char *);
	if (!s)
	{
		free(s);
		s = "(null)";
	}
	j = ft_strlen(s) > elem.accuracy ? elem.accuracy : ft_strlen(s);
	while (elem.width && (size_t)(elem.width - i) > j && !(ft_strchr(elem.options, '-')))
	{
		ft_putchar(' ');
		i++;
	}
	j = 0;
	if ((int)ft_strlen(s) > elem.accuracy && elem.accuracy != -1)
	{
		while (j < elem.accuracy && s[j])
		{
			ft_putchar(s[j]);
			i++;
			j++;
		}
	}
	else
		i += (int)write(1, s, ft_strlen((char *)s));
	j = ft_strlen(s) > elem.accuracy ? elem.accuracy : ft_strlen(s);
	while (elem.width && (size_t)elem.width > j && ft_strchr(elem.options, '-'))
	{
		ft_putchar(' ');
		elem.width--;
		i++;
	}
	return (i);
}
