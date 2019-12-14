/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utf_8.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 09:35:12 by ksharlen          #+#    #+#             */
/*   Updated: 2019/07/21 10:25:53 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned			set_mask_10(unsigned val, unsigned bytes)
{
	--bytes;
	while (bytes)
	{
		SET_BIT(val, (bytes * 8) - 1);
		bytes--;
	}
	return (val);
}

static unsigned char	get_6_bits(unsigned unicode)
{
	unsigned char		buf;

	buf = unicode;
	buf <<= 2;
	buf >>= 2;
	return (buf);
}

t_utf					push_unicode(t_utf utf)
{
	int					index;
	unsigned			bytes;

	bytes = utf.bytes;
	index = 0;
	if (bytes > 1)
	{
		while (bytes)
		{
			utf.utf_sym = ft_bitscpy(utf.utf_sym,\
			get_6_bits(utf.unicode), index);
			utf.unicode >>= 6;
			index += 8;
			--bytes;
		}
	}
	else
		utf.utf_sym = utf.unicode;
	return (utf);
}

unsigned				def_num_bytes(wchar_t unicode)
{
	unsigned			bytes;

	bytes = 0;
	if (unicode >= 0 && unicode < 128)
		bytes = 1;
	else if (unicode >= 128 && unicode < 2048)
		bytes = 2;
	else if (unicode >= 2048 && unicode < 65536)
		bytes = 3;
	else if (unicode >= 65536 && unicode < 1114112)
		bytes = 4;
	return (bytes);
}

unsigned				inst_mask(t_utf utf)
{
	unsigned			mask;

	mask = 0;
	utf.utf_sym = 0;
	if (utf.bytes > 1)
	{
		mask = ft_set_bits(mask, utf.bytes, utf.bytes - 1);
		utf.utf_sym = ft_bitscpy(utf.utf_sym, mask,\
			(utf.bytes * 8) - utf.bytes);
		utf.utf_sym = set_mask_10(utf.utf_sym, utf.bytes);
	}
	return (utf.utf_sym);
}
