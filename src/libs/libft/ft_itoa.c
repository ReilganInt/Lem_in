/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 12:41:30 by cormund           #+#    #+#             */
/*   Updated: 2019/04/18 17:17:21 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int		l;

	l = 0;
	if (n <= 0)
		l++;
	while (n)
	{
		l++;
		n /= 10;
	}
	return (l);
}

char		*ft_itoa(int n)
{
	char	*fresh;
	int		l;
	int		minus;

	minus = 1;
	l = ft_len(n);
	fresh = ft_strnew(l);
	if (fresh)
	{
		if (n < 0)
		{
			*fresh = '-';
			minus = -1;
		}
		if (n == 0)
			*fresh = '0';
		while (n)
		{
			fresh[--l] = n % 10 * minus + '0';
			n /= 10;
		}
	}
	return (fresh);
}
