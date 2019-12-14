/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc_int_mas.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 13:56:56 by cormund           #+#    #+#             */
/*   Updated: 2019/09/23 18:22:23 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			**ft_memalloc_int_mas(ssize_t y, ssize_t x)
{
	int		**mas;
	ssize_t	i;

	if (!(mas = (int **)malloc(sizeof(int*) * (y + 1))))
		return (NULL);
	i = 0;
	while (i != x)
	{
		if (!(mas[i] = (int *)malloc(sizeof(int) * x)))
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
