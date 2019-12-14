/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_to_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 08:18:38 by marvin            #+#    #+#             */
/*   Updated: 2019/07/20 13:33:41 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned char		*size_work(unsigned char *str, size_t size_num)
{
	if (g_spec.flags & DASH)
		ft_memset(str + size_num, ' ', g_spec.width - size_num);
	else
	{
		ft_memset(str, ' ', g_spec.width - size_num);
		str += g_spec.width - size_num;
	}
	return (str);
}

unsigned char		chr_space_plus_dec(void)
{
	if (g_spec.flags & DEC)
		return ('-');
	if (g_spec.flags & PLUS)
		return ('+');
	return (' ');
}

static int			ft_size_num_for_int(long long int num)
{
	int				l;
	long long int	num_cp;

	num_cp = num;
	l = g_spec.flags & DOT && g_spec.accuracy == 0 && num == 0 ? 0 : 1;
	while (num_cp /= 10)
		++l;
	g_spec.flags & DOT && g_spec.accuracy > l ? l = g_spec.accuracy : 0;
	g_spec.flags & SPACE || g_spec.flags & PLUS || num < 0 ? ++l : 0;
	num < 0 ? g_spec.flags |= DEC : 0;
	g_spec.flags & ZERO && g_spec.width > l && !(g_spec.flags & DASH) &&\
	!(g_spec.flags & DOT) ? l = g_spec.width : 0;
	return (l);
}

static void			push_num_to_str(unsigned char *buf,
					long long int num, size_t size_num)
{
	short			sign;

	sign = ((num < 0) ? -1 : 1);
	while (size_num--)
	{
		buf[size_num] = num % 10 * sign + '0';
		num /= 10;
	}
	if (g_spec.flags & SPACE || g_spec.flags & PLUS || g_spec.flags & DEC)
		buf[0] = chr_space_plus_dec();
}

void				int_to_str(long long int num)
{
	int				size_num;
	size_t			size_str;
	unsigned char	*buf;

	size_num = ft_size_num_for_int(num);
	size_str = (size_num < g_spec.width ? g_spec.width : size_num);
	buf = check_buf(size_str);
	push_num_to_str(g_spec.width > size_num ?
		size_work(buf, size_num) : buf, num, size_num);
	if (SIZE_BUF < size_str)
		write_and_free_malloc(buf, size_str);
}
