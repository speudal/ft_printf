/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 18:54:13 by tduval            #+#    #+#             */
/*   Updated: 2018/11/30 23:45:42 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_atoi(const char *str)
{
	long long	res;
	int			neg;
	int			i;

	i = -1;
	res = 0;
	while (str[++i] == 32 || (str[i] > 8 && str[i] < 14))
		;
	neg = (str[i] == '-' ? 1 : 0);
	i += (str[i] == '+' || str[i] == '-' ? 1 : 0);
	while (ft_isdigit(str[i]))
	{
		res += str[i] - 48;
		res *= (ft_isdigit((str[i + 1])) ? 10 : 1);
		if (res < 0)
			return (neg == 0 ? -1 : 0);
		++i;
	}
	return (neg == 1 ? (int)-res : (int)res);
}
