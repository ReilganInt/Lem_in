/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 14:44:43 by cormund           #+#    #+#             */
/*   Updated: 2019/04/18 19:38:23 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr(int n)
{
	char	tab[10];
	int		len;
	int		minus;

	minus = 1;
	len = 0;
	if (n < 0)
	{
		minus = -1;
		ft_putchar('-');
	}
	if (n == 0)
		ft_putchar('0');
	while (n)
	{
		tab[len++] = n % 10 * minus + '0';
		n /= 10;
	}
	while (len)
		ft_putchar(tab[--len]);
}
