/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:45:35 by cormund           #+#    #+#             */
/*   Updated: 2019/04/19 10:28:51 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *fresh;
	char *buf;

	fresh = NULL;
	if (s && f)
	{
		fresh = ft_strnew(ft_strlen(s));
		buf = fresh;
		if (fresh)
			while (*s)
				*buf++ = f(*s++);
	}
	return (fresh);
}
