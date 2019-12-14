/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 14:16:15 by ksharlen          #+#    #+#             */
/*   Updated: 2019/05/15 01:43:18 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memsub(const void *s, unsigned int start, size_t len)
{
	void	*p_ret;
	size_t	i;

	p_ret = NULL;
	if (s)
	{
		i = 0;
		p_ret = ft_memalloc(len);
		if (!p_ret)
			return (NULL);
		while (i < len)
		{
			((unsigned char *)p_ret)[i] = ((unsigned char *)s)[start++];
			i++;
		}
	}
	return (p_ret);
}
