/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_arithmetic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 09:24:29 by cormund           #+#    #+#             */
/*   Updated: 2019/07/24 15:00:13 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			mul_and_norm(t_long *res, unsigned int multiplier, int len)
{
	unsigned int	tmp;
	int				i;

	tmp = 0;
	i = 0;
	while (len)
	{
		res->nbr_tmp[i] *= multiplier;
		if (tmp)
			res->nbr_tmp[i] += tmp;
		if ((tmp = res->nbr_tmp[i] / 10))
			res->nbr_tmp[i] %= 10;
		--len;
		++i;
	}
	while (tmp)
	{
		res->nbr_tmp[i] += tmp;
		if ((tmp = res->nbr_tmp[i] / 10))
			res->nbr_tmp[i] %= 10;
		++i;
	}
	if (i > res->len_tmp)
		res->len_tmp = i;
}

static void			add_and_norm(t_long *res, unsigned int *nbr, int *len)
{
	int				i;

	i = 0;
	while (i != res->len_tmp)
	{
		nbr[i] += res->nbr_tmp[i];
		while (nbr[i] > 9)
		{
			nbr[i + 1] += 1;
			nbr[i] -= 10;
		}
		++i;
	}
	while (nbr[i] > 9)
	{
		nbr[i + 1] += 1;
		nbr[i] -= 10;
		++i;
	}
	while (nbr[i])
		++i;
	if (i > *len)
		*len = i;
}

static void			long_arithmetic_power(short int exponenta, t_long *res)
{
	res->nbr_tmp[0] = 1;
	res->len_tmp = (exponenta >= 0 ? 1 : CHECK_MOD(exponenta));
	while (exponenta >= 28)
	{
		mul_and_norm(res, TWO_POW_TWENTY_EIGHT, res->len_tmp);
		exponenta -= 28;
	}
	if (exponenta > 0)
		mul_and_norm(res, ft_pow(2, exponenta), res->len_tmp);
	while (exponenta <= -12)
	{
		mul_and_norm(res, FIVE_POW_TWENTEEN, res->len_tmp);
		exponenta += 12;
	}
	if (exponenta < 0)
		mul_and_norm(res, ft_pow(5, CHECK_MOD(exponenta)), res->len_tmp);
}

void				long_arithmetic(t_uni real_num, t_long *res)
{
	int				i;

	i = 64;
	res->len_int = 1;
	while (i--)
	{
		if (real_num.bits.mantissa >> i & 1)
		{
			long_arithmetic_power(real_num.bits.exp, res);
			if (real_num.bits.exp >= 0)
				add_and_norm(res, res->nbr_int, &res->len_int);
			else
				add_and_norm(res, res->nbr_fract + res->len_fract -\
										res->len_tmp, &res->len_tmp);
			ft_bzero(res->nbr_tmp, sizeof(int) * res->len_tmp);
		}
		--real_num.bits.exp;
	}
	ft_memcpy(res->nbr_tmp, res->nbr_fract, res->len_fract * sizeof(int));
	ft_memcpy(res->nbr_tmp + res->len_fract, res->nbr_int,\
								res->len_int * sizeof(int));
	res->len_tmp = res->len_int + res->len_fract;
	res->nbr_dot = res->nbr_tmp + res->len_fract;
	free(res->nbr_int);
	free(res->nbr_fract);
}

void				malloc_long(t_uni *real_num, t_long *res)
{
	int				i;
	short int		exp;

	exp = real_num->bits.exp;
	res->len_int = (exp > 0 ? exp / 3 + 2 : 2);
	i = 64;
	while (i-- && !(real_num->bits.mantissa >> (63 - i) & 1))
		;
	exp -= i;
	res->len_fract = (exp < -6 && real_num->bits.mantissa ? NUM_MOD(exp) : 6);
	res->len_tmp = res->len_int + res->len_fract;
	res->nbr_int = (unsigned int *)malloc(sizeof(int) * res->len_int);
	res->nbr_fract = (unsigned int *)malloc(sizeof(int) * (res->len_fract + 1));
	res->nbr_tmp = (unsigned int *)malloc(sizeof(int) * res->len_tmp);
	if (!res->nbr_int || !res->nbr_tmp || !res->nbr_fract)
		exit(0);
	ft_bzero(res->nbr_int, sizeof(int) * res->len_int);
	ft_bzero(res->nbr_tmp, sizeof(int) * res->len_tmp);
	ft_bzero(res->nbr_fract, sizeof(int) * (res->len_fract + 1));
}
