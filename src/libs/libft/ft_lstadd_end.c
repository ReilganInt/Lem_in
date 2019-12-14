/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 10:46:34 by ksharlen          #+#    #+#             */
/*   Updated: 2019/04/19 11:55:41 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_end(t_list **begin_list, t_list *elem)
{
	t_list *res;

	if (begin_list)
	{
		if (!(*begin_list))
			(*begin_list) = elem;
		else
		{
			res = (*begin_list);
			while (res->next)
				res = res->next;
			res->next = elem;
		}
	}
}
