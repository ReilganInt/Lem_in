/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 10:55:03 by cormund           #+#    #+#             */
/*   Updated: 2019/04/19 11:01:18 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t len_d;
	size_t len_s;
	size_t n;

	len_s = ft_strlen(src);
	if ((len_d = ft_strlen(dst)) >= size)
		n = len_s + size;
	else
	{
		n = len_d + len_s;
		while (*(src) != '\0' && len_d < (size - 1))
		{
			*(dst + len_d) = *(src++);
			len_d++;
		}
		*(dst + len_d) = '\0';
	}
	return (n);
}
