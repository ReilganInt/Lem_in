/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 16:42:45 by cormund           #+#    #+#             */
/*   Updated: 2019/04/17 12:24:51 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*fresh;
	char	*buf;
	size_t	i;

	fresh = NULL;
	if (s && f)
	{
		fresh = ft_strnew(ft_strlen(s));
		buf = fresh;
		i = 0;
		if (fresh)
			while (*s)
				*buf++ = f(i++, *s++);
	}
	return (fresh);
}
