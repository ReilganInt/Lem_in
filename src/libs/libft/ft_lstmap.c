/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 16:06:15 by cormund           #+#    #+#             */
/*   Updated: 2019/04/19 12:07:35 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*fresh;

	fresh = NULL;
	if (lst && f)
	{
		fresh = f(lst);
		fresh->next = ft_lstmap(lst->next, f);
		if (!fresh->next && lst->next)
		{
			free(fresh->content);
			ft_memdel((void **)fresh);
			return (NULL);
		}
	}
	return (fresh);
}
