/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 14:56:20 by ksharlen          #+#    #+#             */
/*   Updated: 2019/05/15 01:45:39 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnjoin(const char *str1, const char *str2,
	size_t num_str1, size_t num_str2)
{
	char	*new;

	new = NULL;
	if (str1 && str2)
	{
		new = ft_strnew(num_str1 + num_str2);
		ft_memcpy(new, str1, num_str1);
		ft_memcpy(new + num_str1, str2, num_str2);
	}
	return (new);
}
