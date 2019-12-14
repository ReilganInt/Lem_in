/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 20:21:06 by cormund           #+#    #+#             */
/*   Updated: 2019/04/23 15:10:07 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*fresh;
	size_t	len;

	fresh = NULL;
	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		if ((fresh = ft_strnew(len)))
		{
			fresh = ft_strcpy(fresh, s1);
			fresh = ft_strcat(fresh, s2);
		}
	}
	return (fresh);
}
