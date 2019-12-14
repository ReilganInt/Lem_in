/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_spec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 09:57:05 by ksharlen          #+#    #+#             */
/*   Updated: 2019/07/23 09:21:30 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			define_width(void)
{
	if (g_spec.width > 1)
		g_spec.width -= 1;
}

static char			define_flag_zero(void)
{
	return (g_spec.flags & ZERO ? '0' : ' ');
}

static void			put_width(void)
{
	char			sym;

	sym = define_flag_zero();
	define_width();
	if (g_spec.flags & DASH)
	{
		sym = ' ';
		work_buf(&g_spec.spec, 1);
		memset_buf(sym, g_spec.width);
	}
	else
	{
		memset_buf(sym, g_spec.width);
		work_buf(&g_spec.spec, 1);
	}
}

void				not_spec(void)
{
	if (g_spec.spec)
		put_width();
}
