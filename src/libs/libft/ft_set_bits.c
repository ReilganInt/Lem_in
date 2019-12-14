/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_bits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 08:48:55 by ksharlen          #+#    #+#             */
/*   Updated: 2019/07/21 10:23:33 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned	ft_set_bits(unsigned val, unsigned bits, unsigned num)
{
	while (bits--)
		val = ft_set_bit(val, num--);
	return (val);
}
