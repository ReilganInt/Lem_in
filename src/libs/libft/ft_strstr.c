/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:16:56 by cormund           #+#    #+#             */
/*   Updated: 2019/04/19 10:40:06 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	size_t	len_hay;
	size_t	len_nee;

	if (!*(needle))
		return ((char*)haystack);
	len_hay = ft_strlen(haystack);
	len_nee = ft_strlen(needle);
	while (*haystack && len_nee <= len_hay)
	{
		if (*haystack == *needle && ft_memcmp(haystack, needle, len_nee) == 0)
			return ((char*)haystack);
		haystack++;
		len_hay--;
	}
	return ((void*)0);
}
