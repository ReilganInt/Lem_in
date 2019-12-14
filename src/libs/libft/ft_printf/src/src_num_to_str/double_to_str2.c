/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_to_str2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 10:47:39 by cormund           #+#    #+#             */
/*   Updated: 2019/07/24 16:50:00 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				banker_rounding(unsigned int *nbr, int i, int len)
{
	if (i < 0 || i >= len)
		return (0);
	if (nbr[i] > 5)
		return (1);
	if (nbr[i] == 5)
	{
		if ((i + 1) == len || nbr[i + 1] & 1)
			return (1);
		while (i--)
		{
			if (nbr[i])
				return (1);
		}
	}
	return (0);
}

static ssize_t	rounding_number(t_long *res, unsigned int *nbr, ssize_t i)
{
	if (i >= 0 && banker_rounding(nbr, i, res->len_tmp) && (nbr[++i] += 1))
		while (i != res->len_tmp && nbr[i] == 10)
		{
			nbr[i] = 0;
			nbr[++i] += 1;
		}
	if (nbr[res->len_tmp])
	{
		++res->len_int;
		++res->len_tmp;
		return (1);
	}
	return (0);
}

static void		check_e(t_long *res)
{
	ssize_t		len;
	int			tmp;
	int			len_tmp;

	res->e = 0;
	len = res->len_tmp - 1;
	if (res->nbr_tmp[len])
		res->e = res->len_int - 1;
	else
		while (!res->nbr_tmp[len] && len--)
			--res->e;
	if (!res->nbr_tmp[len] && len == -1)
		res->e = 0;
	len_tmp = (res->e >= 0 ? res->len_tmp : res->len_tmp + res->e);
	len = len_tmp - 2 - (g_spec.flags & DOT ? g_spec.accuracy : 6);
	tmp = 0;
	if (len >= 0 && banker_rounding(res->nbr_tmp, len++, len_tmp) && ++tmp)
		while (len != len_tmp && (res->nbr_tmp[len] + tmp) == 10)
			++len;
	if (len == len_tmp)
		++res->e;
}

static ssize_t	size_num_for_long_g(t_long *res)
{
	ssize_t		len;

	if (!(g_spec.flags & DOT))
		g_spec.accuracy = 6;
	else if (!g_spec.accuracy)
		g_spec.accuracy = 1;
	g_spec.flags |= DOT;
	check_e(res);
	if (-4 <= res->e && res->e < g_spec.accuracy)
	{
		g_spec.spec -= 1;
		g_spec.accuracy -= res->e + 1;
		len = res->len_tmp - g_spec.accuracy - res->len_int;
	}
	else
	{
		g_spec.spec -= 2;
		g_spec.accuracy -= 1;
		len = res->len_tmp - g_spec.accuracy + (res->e < 0 ? res->e : 0) - 1;
		res->nbr_dot = res->nbr_tmp + res->len_tmp + (res->e < 0 ? res->e : -1);
	}
	return (delete_zero(res, res->nbr_tmp, len));
}

size_t			size_num_for_long(t_long *res)
{
	ssize_t		l;

	l = (g_spec.spec == 'g' || g_spec.spec == 'G' ?\
		size_num_for_long_g(res) : 0);
	if (g_spec.spec == 'f' || g_spec.spec == 'F')
	{
		l += res->len_int + (g_spec.flags & DOT ? g_spec.accuracy : 6);
		l += rounding_number(res, res->nbr_tmp, res->len_tmp - l - 1);
	}
	else
	{
		l += (g_spec.flags & DOT ? g_spec.accuracy + 1 : 7);
		check_e(res);
		res->len_tmp += (res->e < 0 ? res->e : 0);
		rounding_number(res, res->nbr_tmp, res->len_tmp - l - 1);
		l += 3 + ft_size_num((CHECK_MOD(res->e) / 10));
		res->len_fract += res->e;
		res->len_int = 1;
	}
	if (res->nbr_dot && (g_spec.flags & HASH || !(g_spec.flags & DOT) ||\
	(g_spec.flags & DOT && g_spec.accuracy)))
		++l;
	if (g_spec.flags & SPACE || g_spec.flags & PLUS || g_spec.flags & DEC)
		++l;
	return (l);
}
