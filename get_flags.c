/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 14:24:55 by tduval            #+#    #+#             */
/*   Updated: 2018/11/28 23:39:46 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static t_flags	*split_get(t_flags *list, const char *str)
{
	int	ct;
	int	i;
	int	p;

	ct = 0;
	i = -1;
	p = 0;
	while (str[++i])
	{
		if (str[i] == '%' && !p)
		{
			i++;
			if ((list[ct] = fill_flags(str + i)).wrong)
				return (0);
			if (list[ct].conv == '%' && str[i] != '%')
				p = 1;
			ct++;
		}
		else if (str[i] == '%' && p)
			p = 0;
	}
	return (list);
}

t_flags			*get_flags(const char *str)
{
	t_flags *list;
	int		ct;
	int		i;
	int		p;

	ct = 0;
	i = -1;
	p = 0;
	while (str[++i])
		if (str[i] == '%')
			ct++;
	if (!(list = (t_flags *)malloc(sizeof(t_flags) * (ct + 1))))
		return (0);
	return (split_get(list, str));
}
