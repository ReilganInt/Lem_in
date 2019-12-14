/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:14:07 by cormund           #+#    #+#             */
/*   Updated: 2019/04/19 10:20:38 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *d, const void *s, int c, size_t n)
{
	while (n--)
	{
		if ((*(unsigned char *)d++ = *(unsigned char *)s++) == (unsigned char)c)
			return (d);
	}
	return ((void*)0);
}
