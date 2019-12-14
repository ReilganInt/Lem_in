/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skipfirst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 20:51:29 by ksharlen          #+#    #+#             */
/*   Updated: 2019/07/27 20:56:59 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_skipfirst(char *str, int sym)
{
	if (str && sym >= 0)
		while (*str == sym && *str)
			str++;
	return (str);
}
