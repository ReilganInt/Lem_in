/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_wchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 18:57:24 by ksharlen          #+#    #+#             */
/*   Updated: 2019/07/24 16:06:31 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_utf				convert_sym_utf8(wchar_t sym)
{
	t_utf			utf;

	utf.bytes = def_num_bytes(sym);
	utf.unicode = sym;
	utf.utf_sym = inst_mask(utf);
	utf = push_unicode(utf);
	return (utf);
}

unsigned char		*push_wchar_in_char(t_utf utf, unsigned char *str)
{
	unsigned char sym;

	while (utf.bytes)
	{
		sym = (utf.utf_sym >> (8 * (utf.bytes - 1)));
		*str = sym;
		str++;
		--utf.bytes;
	}
	return (str);
}

static size_t		bytelen(wchar_t *str)
{
	size_t			len;

	len = 0;
	if (str)
	{
		while (*str)
		{
			len += def_num_bytes(*str);
			str++;
		}
	}
	return (len);
}

unsigned char		*convert_utf8(wchar_t *str, size_t len_utf8)
{
	t_utf			utf;
	size_t			len;
	size_t			index;
	unsigned char	*ret_str;
	unsigned char	*p_ret_str;

	index = 0;
	len = bytelen(str);
	if (!(ret_str = (unsigned char *)ft_memalloc(len + 1)))
		exit(0);
	p_ret_str = ret_str;
	while (index < len_utf8)
	{
		utf = convert_sym_utf8(str[index]);
		p_ret_str = push_wchar_in_char(utf, p_ret_str);
		index++;
	}
	return (ret_str);
}

unsigned char		*push_wchar_to_buf(t_utf utf)
{
	unsigned char	*buf;
	unsigned char	inbuf;

	while (utf.bytes)
	{
		inbuf = (utf.utf_sym >> (8 * (utf.bytes - 1)));
		buf = work_buf(&inbuf, 1);
		--utf.bytes;
	}
	return (buf);
}
