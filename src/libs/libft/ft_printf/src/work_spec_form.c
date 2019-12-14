/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_spec_form.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 13:54:55 by ksharlen          #+#    #+#             */
/*   Updated: 2019/07/23 07:45:42 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		check_star_and_push(va_list form)
{
	int			ret_shift;

	ret_shift = 0;
	if (g_spec.flags & STAR_ACC)
	{
		g_spec.accuracy = va_arg(form, int);
		if (g_spec.accuracy < 0)
		{
			g_spec.accuracy = 0;
			g_spec.flags &= (~(DOT));
		}
		ret_shift = 2;
	}
	else if (g_spec.flags & STAR_WITH)
	{
		g_spec.width = va_arg(form, int);
		if (g_spec.width < 0)
		{
			g_spec.flags |= DASH;
			NUM_MOD(g_spec.width);
		}
		ret_shift = 1;
	}
	return (ret_shift);
}

static int		check_mod(const char *format)
{
	int ret;

	ret = 0;
	if (*format == 'l')
		ret = l_format(*(format + 1));
	else if (*format == 'h')
		ret = h_format(*(format + 1));
	else if (*format == 'j' || *format == 'z' || *format == 't')
		ret = j_z_t_format(*format);
	else if (*format == 'L')
		ret = big_l();
	else
		ret = 1;
	return (ret);
}

static int		find_width_accuracy(const char *format, va_list form)
{
	int			shift;

	if (*format == '*')
	{
		g_spec.flags |= STAR_WITH;
		shift = check_star_and_push(form);
	}
	else if (*format != '.')
	{
		g_spec.width = ft_atoi(format);
		shift = str_size_num(format);
	}
	else if (*format == '.' && *(format + 1) == '*')
	{
		(g_spec.flags |= STAR_ACC) && (g_spec.flags |= DOT);
		shift = check_star_and_push(form);
	}
	else
	{
		g_spec.accuracy = ft_atoi(format + 1);
		shift = str_size_num(format + 1) + 1;
		g_spec.flags |= DOT;
	}
	return (shift);
}

static void		work_spec(const char *format, va_list form)
{
	int			shift_format;

	while (!(ismy(*format) && *format))
	{
		shift_format = 1;
		if (*format == '#')
			g_spec.flags |= HASH;
		else if (*format == '+')
			g_spec.flags |= PLUS;
		else if (*format == '-')
			g_spec.flags |= DASH;
		else if (*format == ' ')
			g_spec.flags |= SPACE;
		else if (*format == '0')
			g_spec.flags |= ZERO;
		else if ((ft_isdigit(*format) || *format == '*') ||
			(*format == '.'))
			shift_format = find_width_accuracy(format, form);
		else
			shift_format = check_mod(format);
		format += shift_format;
	}
}

void			work_spec_form(const char *format, va_list form)
{
	g_spec.flags = 0;
	g_spec.width = 0;
	g_spec.accuracy = 0;
	g_spec.mod = 0;
	work_spec(format, form);
}
