/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 14:19:03 by cormund           #+#    #+#             */
/*   Updated: 2019/04/18 15:11:45 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (*alst && alst && del)
	{
		if ((*alst)->next)
			ft_lstdel(&(*alst)->next, del);
		del((*alst)->content, (*alst)->content_size);
		ft_memdel((void **)alst);
	}
}
