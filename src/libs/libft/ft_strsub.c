/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 18:06:19 by cormund           #+#    #+#             */
/*   Updated: 2019/04/16 14:13:55 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *fresh;

	if (!s)
		return (NULL);
	if ((fresh = ft_strnew(len)))
		ft_strncpy(fresh, (s + start), len);
	return (fresh);
}
