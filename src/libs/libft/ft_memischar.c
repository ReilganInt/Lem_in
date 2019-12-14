/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memischar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 12:26:35 by ksharlen          #+#    #+#             */
/*   Updated: 2019/06/03 14:01:43 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memischar(const char *str, int n, size_t size)
{
	while (size-- && *str)
		if (*str++ == n)
			return (1);
	return (0);
}
