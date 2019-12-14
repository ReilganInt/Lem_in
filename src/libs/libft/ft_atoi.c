/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:55:15 by cormund           #+#    #+#             */
/*   Updated: 2019/04/18 19:55:38 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int							ft_atoi(const char *s)
{
	unsigned long long int	res;
	int						sing;

	res = 0;
	sing = 1;
	while (ft_isspace(*s))
		s++;
	if (*s == '-' || *s == '+')
		if (*(s++) == '-')
			sing = -1;
	while (ft_isdigit(*s) && res <= MAXLLI / 10)
		res = res * 10 + (*(s++) - '0');
	if (sing == -1 && (res > MAXLLI || ft_isdigit(*s)))
		res = 0;
	else if (res > MAXLLI || ft_isdigit(*s))
		res = -1;
	return (res * sing);
}
