/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:17:37 by cormund           #+#    #+#             */
/*   Updated: 2019/04/18 19:38:41 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int n, int fd)
{
	char	tab[10];
	int		len;
	int		minus;

	minus = 1;
	len = 0;
	if (n < 0)
	{
		minus = -1;
		ft_putchar_fd('-', fd);
	}
	if (n == 0)
		ft_putchar_fd('0', fd);
	while (n)
	{
		tab[len++] = n % 10 * minus + '0';
		n /= 10;
	}
	while (len)
		ft_putchar_fd(tab[--len], fd);
}
