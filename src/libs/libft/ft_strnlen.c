/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 01:46:18 by ksharlen          #+#    #+#             */
/*   Updated: 2019/05/15 01:46:59 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strnlen(const char *str, int n)
{
	size_t len;

	len = 0;
	if (str)
	{
		while (*str && *str++ != n)
			len++;
	}
	return (len);
}
