/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:41:24 by cormund           #+#    #+#             */
/*   Updated: 2019/04/19 12:56:48 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *tmp;

	tmp = NULL;
	while (*s)
	{
		if (*s == (char)c)
			tmp = (char*)s;
		s++;
	}
	if ((char)c == '\0' && !*s)
		tmp = (char*)s;
	return (tmp);
}
