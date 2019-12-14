/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 15:05:30 by ksharlen          #+#    #+#             */
/*   Updated: 2019/05/15 01:32:02 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memnjoin(const void *s1, const void *s2, size_t num1, size_t num2)
{
	void	*p_ret;

	p_ret = NULL;
	if (s1 && s2)
	{
		p_ret = ft_memalloc(num1 + num2);
		if (!p_ret)
			return (NULL);
		ft_memcpy(p_ret, s1, num1);
		ft_memcpy(p_ret + num1, s2, num2);
	}
	return (p_ret);
}
