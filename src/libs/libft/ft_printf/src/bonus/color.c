/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 08:56:37 by ksharlen          #+#    #+#             */
/*   Updated: 2019/07/21 10:25:06 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned char	*ft_check_color(const char *string)
{
	unsigned char		*color;

	if (!(color = (unsigned char *)ft_memalloc(sizeof(unsigned char) * 11)))
		return (NULL);
	if (!ft_memcmp(string, "black", 5) && *(string + 5) == '}')
		color = (unsigned char *)";30m";
	else if (!ft_memcmp(string, "red", 3) && *(string + 3) == '}')
		color = (unsigned char *)";31m";
	else if (!ft_memcmp(string, "green", 5) && *(string + 5) == '}')
		color = (unsigned char *)";32m";
	else if (!ft_memcmp(string, "yellow", 6) && *(string + 6) == '}')
		color = (unsigned char *)";33m";
	else if (!ft_memcmp(string, "blue", 4) && *(string + 4) == '}')
		color = (unsigned char *)";34m";
	else if (!ft_memcmp(string, "purple", 6) && *(string + 6) == '}')
		color = (unsigned char *)";35m";
	else if (!ft_memcmp(string, "gay", 3) && *(string + 3) == '}')
		color = (unsigned char *)";36m";
	else if (!ft_memcmp(string, "white", 5) && *(string + 5) == '}')
		color = (unsigned char *)";37m";
	else
		return (NULL);
	return ((unsigned char *)ft_strdup((const char *)color));
}

static void				ft_push_buf_and_clean_string(unsigned char *str_clean,\
																int size_str)
{
	work_buf((unsigned char *)"\e[", 2);
	work_buf(str_clean, size_str);
	free(str_clean);
	str_clean = NULL;
}

int						color_format(const char *string)
{
	unsigned char		*color;
	int					len;

	if ((color = ft_check_color(string)) && g_spec.fd == 1)
	{
		len = ft_strnlen(string, '}') + 1;
		ft_push_buf_and_clean_string(color, ft_strlen((const char *)color));
		return (len + 2);
	}
	else
		return (0);
}
