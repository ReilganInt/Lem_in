/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 20:08:06 by cormund           #+#    #+#             */
/*   Updated: 2019/04/19 10:24:24 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *buf;

	buf = dst;
	while (len && *src)
	{
		*buf++ = *src++;
		len--;
	}
	while (len--)
		*buf++ = '\0';
	return (dst);
}
