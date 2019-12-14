/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 19:19:56 by cormund           #+#    #+#             */
/*   Updated: 2019/04/19 10:20:51 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *d;
	unsigned char *s;

	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	if (s == d)
		return (dst);
	if (s > d)
		ft_memcpy(d, s, len);
	else
		while (len--)
			*(d + len) = *(s + len);
	return (dst);
}
