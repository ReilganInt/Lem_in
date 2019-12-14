/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:47:36 by cormund           #+#    #+#             */
/*   Updated: 2019/04/11 18:00:16 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t len_hay;
	size_t len_nee;

	if (!*needle)
		return ((char*)haystack);
	if ((len_hay = ft_strlen(haystack)) > len)
		len_hay = len;
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
