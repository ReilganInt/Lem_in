/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 12:00:00 by ksharlen          #+#    #+#             */
/*   Updated: 2019/07/21 10:07:45 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isstr(const char *str, const char *check_symbols)
{
	while (*str)
	{
		if (ft_ischar(check_symbols, *str))
			return (1);
		str++;
	}
	return (0);
}
