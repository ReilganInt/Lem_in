/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 17:43:13 by cormund           #+#    #+#             */
/*   Updated: 2019/05/08 09:54:53 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcut(char *s, char c)
{
	char	*p;
	char	*fresh;

	if ((p = ft_strchr(s, c)))
		fresh = ft_strndup(s, p - s);
	else
		fresh = ft_strdup(s);
	return (fresh);
}
