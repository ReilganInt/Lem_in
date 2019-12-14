/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_num_sys.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 19:25:14 by ksharlen          #+#    #+#             */
/*   Updated: 2019/07/23 09:57:25 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long int		pull_signed_int_arg(va_list format)
{
	long long int			ret;

	ret = 0;
	if (g_spec.mod == ZERO)
		ret = (char)va_arg(format, int);
	else if (g_spec.mod == PLUS)
		ret = (short)va_arg(format, int);
	else if (g_spec.mod == DASH)
		ret = va_arg(format, long int);
	else if (g_spec.mod == SPACE)
		ret = va_arg(format, long long);
	else if (g_spec.mod == HASH)
		ret = va_arg(format, intmax_t);
	else if (g_spec.mod == DOT)
		ret = va_arg(format, ssize_t);
	else if (g_spec.mod == DEC)
		ret = va_arg(format, ptrdiff_t);
	else if (g_spec.spec == 'D' && !g_spec.mod)
		ret = va_arg(format, long int);
	else
		ret = va_arg(format, int);
	return (ret);
}

static unsigned long long	pull_unsigned_int_arg(va_list format)
{
	unsigned long long int	ret;

	ret = 0;
	if ((g_spec.spec == 'U' || g_spec.spec == 'O'))
		ret = va_arg(format, unsigned long);
	else if (g_spec.mod == ZERO)
		ret = (unsigned char)va_arg(format, unsigned int);
	else if (g_spec.mod == PLUS)
		ret = (unsigned short)va_arg(format, unsigned int);
	else if (g_spec.mod == DASH)
		ret = va_arg(format, unsigned long);
	else if (g_spec.mod == SPACE)
		ret = va_arg(format, unsigned long long);
	else if (g_spec.mod == HASH)
		ret = va_arg(format, uintmax_t);
	else if (g_spec.mod == DOT || g_spec.mod == DEC)
		ret = va_arg(format, size_t);
	else if (g_spec.spec == 'p')
		ret = va_arg(format, uintptr_t);
	else
		ret = va_arg(format, unsigned int);
	return (ret);
}

void						select_num_sys(va_list format)
{
	long long int			s_val;
	unsigned long long int	u_val;

	if (check_the_entry(SIGNED_INT, g_spec.spec))
	{
		s_val = pull_signed_int_arg(format);
		int_to_str(s_val);
	}
	else if (check_the_entry(UNSIGNED_INT, g_spec.spec))
	{
		u_val = pull_unsigned_int_arg(format);
		base_to_str(u_val);
	}
}
