/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_to_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 16:06:53 by ksharlen          #+#    #+#             */
/*   Updated: 2019/07/24 16:51:21 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		define_spec(const char *format_string)
{
	format_string += g_spec.shift_spec;
	g_spec.spec = *format_string;
}

static void		count_sym_to_spec(const char *format)
{
	g_spec.spec = 0;
	while (!ismy(*format) && *format)
	{
		++g_spec.shift_spec;
		++format;
	}
}

static void		control_var(va_list format)
{
	if (check_the_entry(NUM_INT, g_spec.spec))
		select_num_sys(format);
	else if (check_the_entry(NUM_STRING, g_spec.spec))
	{
		if (g_spec.spec == 'c' || g_spec.spec == 'C')
			char_to_str(format);
		else if (g_spec.spec == 's' || g_spec.spec == 'S')
			str_to_str(format);
	}
	else if (check_the_entry(NUM_DOUBLE, g_spec.spec))
		double_to_str(format);
	else if (check_the_entry(NUM_OTHER, g_spec.spec))
		other_spec(format);
	else
		not_spec();
}

static void		call_fun_format(const char *format, va_list form)
{
	if (*format)
	{
		count_sym_to_spec(format);
		define_spec(format);
		work_spec_form(format, form);
		control_var(form);
	}
	g_spec.shift_spec += (g_spec.spec ? 1 : 0);
}

void			work_to_format(const char *format, va_list form)
{
	while (*format)
	{
		if (*format == '%')
		{
			g_spec.shift_spec = 0;
			++format;
			if (*format)
				call_fun_format(format, form);
			format += g_spec.shift_spec;
		}
		else
		{
			if (*format == '{' && *(format + 1) == '/' &&
				(g_spec.shift_spec = color_format(format + 2)) > 2)
			{
				format += g_spec.shift_spec;
				g_spec.ret_printf -= g_spec.shift_spec;
			}
			else
			{
				work_buf((unsigned char *)format, 1);
				format++;
			}
		}
	}
}
