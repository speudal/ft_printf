/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_li.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 22:45:08 by tduval            #+#    #+#             */
/*   Updated: 2018/11/27 17:08:56 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		print_li(va_list ap, t_flags elem)
{
	return (print_ld(ap, elem));
}
