/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 09:55:01 by cormund           #+#    #+#             */
/*   Updated: 2019/11/06 10:16:54 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_new_line(char **tail, char *newline)
{
	char *line0;
	char *line;
	char *p;
	char *new_tail;

	if (!(line0 = (char *)malloc(sizeof(char) * (newline - *tail + 1))))
		return (NULL);
	line = line0;
	p = *tail;
	while (p != newline)
		*line++ = *p++;
	*line = 0;
	if (!*++p)
		new_tail = NULL;
	else if (!(new_tail = ft_strdup(p)))
		return (NULL);
	free(*tail);
	*tail = new_tail;
	return (line0);
}

static char	*read_more(char *tail, int fd)
{
	char	buf[BUFF_SIZE + 1];
	char	*p;
	int		r;

	if ((r = read(fd, buf, BUFF_SIZE)) < 0)
		return (NULL);
	buf[r] = 0;
	if (tail)
	{
		p = tail;
		if (!(tail = ft_strjoin(tail, r ? buf : "\n")))
			return (NULL);
		free(p);
	}
	else
	{
		if (!r)
			return (NULL);
		if (!(tail = ft_strdup(buf)))
			return (NULL);
	}
	return (tail);
}

static char	*find_newline(char *s)
{
	if (s)
		while (*s)
			if (*s++ == '\n')
				return (s - 1);
	return (NULL);
}

char		*gnl(int fd)
{
	static char	*tail = NULL;
	char		*newline;

	while (1)
	{
		if ((newline = find_newline(tail)))
			return (get_new_line(&tail, newline));
		else if (!(tail = read_more(tail, fd)))
			return (NULL);
	}
}
