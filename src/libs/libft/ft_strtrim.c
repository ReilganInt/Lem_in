/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 09:41:22 by cormund           #+#    #+#             */
/*   Updated: 2019/04/17 12:25:17 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	char	*fresh;
	char	*buf;
	size_t	len;

	fresh = NULL;
	if (s)
	{
		while (*s == ' ' || *s == '\n' || *s == '\t')
			s++;
		if ((len = ft_strlen(s)))
			while (len-- && (s[len] == ' ' || s[len] == '\n' || s[len] == '\t'))
				;
		if (len)
			len += 1;
		fresh = ft_strnew(len);
		buf = fresh;
		if (fresh)
			while (len)
			{
				*buf++ = *s++;
				len--;
			}
	}
	return (fresh);
}
