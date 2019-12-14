/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 09:42:43 by ksharlen          #+#    #+#             */
/*   Updated: 2019/04/23 11:14:31 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (alst && new)
	{
		if (!(*alst))
		{
			(*alst) = new;
			new->next = NULL;
		}
		else
		{
			new->next = (*alst);
			(*alst) = new;
		}
	}
}
