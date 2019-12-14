/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitscpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 08:52:06 by ksharlen          #+#    #+#             */
/*   Updated: 2019/07/21 10:06:18 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned	ft_bitscpy(unsigned value, unsigned inval, unsigned num)
{
	return (value | (inval << num));
}
