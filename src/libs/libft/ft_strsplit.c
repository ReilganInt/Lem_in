/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 16:51:01 by cormund           #+#    #+#             */
/*   Updated: 2019/05/14 11:55:25 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_free_mas(char **mas, size_t i)
{
	while (i)
	{
		free(mas[i]);
		i--;
	}
	free(mas);
}

static size_t	ft_count_symbols(const char *s, char c)
{
	size_t		len;

	len = 0;
	while (*s != c && *s)
	{
		len++;
		s++;
	}
	return (len);
}

static int		ft_malloc_mas(char **mas, char const *s, char c, size_t count)
{
	size_t		i;
	size_t		j;
	size_t		len;

	i = 0;
	j = 0;
	while (count--)
	{
		while (*s == c)
			s++;
		len = ft_count_symbols(s, c);
		mas[i] = ft_strnew(len);
		if (!mas[i])
		{
			ft_free_mas(mas, i);
			return (1);
		}
		mas[i] = ft_strncpy(mas[i], s, len);
		i++;
		s += len;
	}
	mas[i] = NULL;
	return (0);
}

static size_t	ft_count_strings(char const *s, char c)
{
	size_t		count_w;
	int			check_in;

	count_w = 0;
	check_in = 0;
	while (*s)
	{
		if (*s == c)
			check_in = 0;
		else if (check_in == 0)
		{
			count_w++;
			check_in = 1;
		}
		s++;
	}
	return (count_w);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t		count_s;
	char		**mas;

	if (!s)
		return (NULL);
	count_s = ft_count_strings(s, c);
	mas = (char **)ft_memalloc(sizeof(char *) * (count_s + 1));
	if (!mas)
		return (NULL);
	if (ft_malloc_mas(mas, s, c, count_s))
		return (NULL);
	else
		return (mas);
}
