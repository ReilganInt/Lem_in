/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc_char_2xmas.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 11:33:07 by cormund           #+#    #+#             */
/*   Updated: 2019/11/13 11:36:08 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_memalloc_char_2xmas(ssize_t y, ssize_t x)
{
	char	**mas;
	ssize_t	i;

	if (!(mas = (char **)malloc(sizeof(char*) * (y + 1))))
		return (NULL);
	i = 0;
	while (i != x)
	{
		if (!(mas[i] = (char *)ft_memalloc(sizeof(char) * x)))
		{
			while (i--)
				free(mas[i]);
			free(mas);
			return (NULL);
		}
		++i;
	}
	mas[y] = NULL;
	return (mas);
}
