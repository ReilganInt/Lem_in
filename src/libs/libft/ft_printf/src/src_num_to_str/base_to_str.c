/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_to_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 17:11:44 by cormund           #+#    #+#             */
/*   Updated: 2019/07/22 16:35:27 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						base_depth(unsigned long long int num, int base)
{
	int					depth;
	unsigned long long	num_cp;

	num_cp = num;
	depth = 1;
	while (num_cp /= base)
		++depth;
	if (g_spec.flags & HASH && num && base != 16)
		++depth;
	if (g_spec.flags & DOT && g_spec.accuracy > depth)
		depth = g_spec.accuracy;
	if (g_spec.flags & HASH && num && base == 16)
		depth += 2;
	if (g_spec.flags & ZERO && !(g_spec.flags & DOT) &&
		!(g_spec.flags & DASH) && g_spec.width > depth)
		depth = g_spec.width;
	if (g_spec.flags & DOT && !g_spec.accuracy && !num)
		depth = 0;
	if (g_spec.flags & HASH && base == 8 &&
		!num && g_spec.flags & DOT && !g_spec.accuracy)
		++depth;
	if (g_spec.spec == 'p' && !num)
		depth += 2;
	return (depth);
}

static void				push_num_to_str(unsigned char *buf,
unsigned long long int num, int base)
{
	int					cp_num;
	size_t				size_num;
	size_t				mod;
	int					ascii;

	size_num = base_depth(num, base);
	cp_num = num;
	ascii = -33 + (g_spec.spec != 'p' ? g_spec.spec : 'x');
	while (size_num--)
	{
		mod = num % base;
		buf[size_num] = (mod > 9 ? mod + ascii : mod + '0');
		num /= base;
	}
	if (g_spec.flags & HASH && cp_num &&
	(g_spec.spec == 'x' || g_spec.spec == 'X'))
		buf[1] = g_spec.spec;
	if (g_spec.flags & HASH && cp_num &&
	(g_spec.spec == 'b' || g_spec.spec == 'B'))
		buf[0] = g_spec.spec;
	if (g_spec.spec == 'p')
		buf[1] = 'x';
}

void					write_and_free_malloc(unsigned char *buf,
size_t size_str)
{
	write_buf_and_clean(WRITE_BUF);
	g_spec.ret_printf += write(g_spec.fd, buf, size_str);
	ft_ustrdel(&buf);
}

static void				ft_work_base(unsigned long long num, int base)
{
	unsigned char		*buf;
	int					size_num;
	size_t				size_str;

	size_num = base_depth(num, base);
	size_str = g_spec.width > size_num ? g_spec.width : size_num;
	buf = check_buf(size_str);
	push_num_to_str(g_spec.width > size_num ?\
		size_work(buf, size_num) : buf, num, base);
	if (SIZE_BUF < size_str)
		write_and_free_malloc(buf, size_str);
}

void					base_to_str(unsigned long long int num)
{
	int					base;

	base = 0;
	if (g_spec.spec == 'x' || g_spec.spec == 'X')
		base = HEX;
	else if (g_spec.spec == 'o' || g_spec.spec == 'O')
		base = OCT;
	else if (g_spec.spec == 'b' || g_spec.spec == 'B')
		base = BIN;
	else if (g_spec.spec == 'u' || g_spec.spec == 'U')
		base = DECEM;
	else if (g_spec.spec == 'p')
	{
		g_spec.flags |= HASH;
		base = HEX;
	}
	ft_work_base(num, base);
}
