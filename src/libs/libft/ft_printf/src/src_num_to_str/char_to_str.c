/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_to_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 13:05:27 by ksharlen          #+#    #+#             */
/*   Updated: 2019/07/22 12:33:08 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			push_buf_sa(t_utf utf)
{
	push_wchar_to_buf(utf);
	memset_buf(' ', g_spec.width);
}

static void			push_buf_as(t_utf utf)
{
	char			for_zero;

	for_zero = ' ';
	if (g_spec.flags & ZERO)
		for_zero = '0';
	memset_buf(for_zero, g_spec.width);
	push_wchar_to_buf(utf);
}

static void			push_buf(t_utf utf)
{
	if (g_spec.width > 1)
	{
		g_spec.width -= 1;
		if (g_spec.flags & DASH)
			push_buf_sa(utf);
		else
			push_buf_as(utf);
	}
	else
		push_wchar_to_buf(utf);
}

void				char_to_str(va_list format)
{
	t_utf			utf;

	if (g_spec.spec == 'C' || (g_spec.spec == 'c' && g_spec.mod == DASH))
	{
		utf.unicode = va_arg(format, wchar_t);
		utf = convert_sym_utf8(utf.unicode);
	}
	else
	{
		utf.utf_sym = (unsigned char)va_arg(format, int);
		utf.bytes = 1;
	}
	push_buf(utf);
}
