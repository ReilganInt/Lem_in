/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:36:28 by cormund           #+#    #+#             */
/*   Updated: 2019/04/19 10:16:59 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*fresh;

	fresh = (t_list *)ft_memalloc(sizeof(t_list));
	if (fresh)
	{
		if (!content)
		{
			fresh->content = NULL;
			fresh->content_size = 0;
		}
		else
		{
			fresh->content_size = content_size;
			if ((fresh->content = (void *)ft_memalloc(content_size)))
				ft_memcpy(fresh->content, content, content_size);
			else
				ft_memdel((void **)fresh);
		}
		if (fresh)
			fresh->next = NULL;
	}
	return (fresh);
}
