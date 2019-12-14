/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_formats.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 16:11:59 by ksharlen          #+#    #+#             */
/*   Updated: 2019/07/20 12:37:29 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		l_format(const int next_symbal)
{
	int mod;
	int shift_size;

	shift_size = 0;
	mod = 0;
	if (next_symbal == 'l')
	{
		if (check_the_entry(NUM_INT, g_spec.spec) ||
			check_the_entry(NUM_OTHER, g_spec.spec))
			mod = SPACE;
		shift_size = 2;
	}
	else
	{
		if (check_the_entry(NUM_INT, g_spec.spec) ||
			check_the_entry(NUM_STRING, g_spec.spec) ||
			check_the_entry(NUM_OTHER, g_spec.spec))
			mod = DASH;
		shift_size = 1;
	}
	if (mod > g_spec.mod)
		g_spec.mod = mod;
	return (shift_size);
}

int		h_format(const int next_symbal)
{
	int mod;
	int shift_size;

	shift_size = 0;
	mod = 0;
	if (next_symbal == 'h')
	{
		if (check_the_entry(NUM_INT, g_spec.spec) ||
			check_the_entry(NUM_OTHER, g_spec.spec))
			mod = ZERO;
		shift_size = 2;
	}
	else
	{
		if (check_the_entry(NUM_INT, g_spec.spec))
			mod = PLUS;
		shift_size = 1;
	}
	if (mod > g_spec.mod)
		g_spec.mod = mod;
	return (shift_size);
}

int		j_z_t_format(const int check_mod)
{
	int mod;

	mod = 0;
	if (check_the_entry(NUM_INT, g_spec.spec))
	{
		if (check_mod == 'z')
			mod = DOT;
		else if (check_mod == 'j')
			mod = HASH;
		else if (check_mod == 't')
			mod = DEC;
	}
	if (mod > g_spec.mod)
		g_spec.mod = mod;
	return (1);
}

int		big_l(void)
{
	if (check_the_entry(NUM_DOUBLE, g_spec.spec))
		g_spec.mod = DASH;
	return (1);
}
