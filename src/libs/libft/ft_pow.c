/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 10:18:52 by ksharlen          #+#    #+#             */
/*   Updated: 2019/07/21 10:08:37 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t		ft_pow(int number, int level)
{
	ssize_t	res;

	res = 1;
	while (level)
	{
		if (level & 1)
			res *= number;
		number *= number;
		level >>= 1;
	}
	return (res);
}
