/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 09:50:56 by cormund           #+#    #+#             */
/*   Updated: 2019/04/19 10:20:05 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *dst_str;

	dst_str = (unsigned char *)dst;
	while (n--)
		*dst_str++ = *(unsigned char *)(src++);
	return ((void *)dst);
}
