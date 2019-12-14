/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   date.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 11:55:56 by cormund           #+#    #+#             */
/*   Updated: 2019/07/21 09:49:27 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_date				get_date(unsigned long long int num_date)
{
	t_date					date;

	date.min = (num_date % 100);
	num_date /= 100;
	date.hours = (num_date % 100);
	num_date /= 100;
	date.days = (num_date % 100);
	num_date /= 100;
	date.months = (num_date % 100);
	num_date /= 100;
	date.years = num_date;
	return (date);
}

static t_date				work_date(t_date date)
{
	int						day_in_month;

	check_ovf_to_time(&date.min, &date.hours, 60, 59);
	check_ovf_to_time(&date.hours, &date.days, 24, 23);
	check_ovf_to_date(&date.months, &date.years, 12, 12);
	day_in_month = get_quan_days(date.months, date.years);
	check_ovf_to_date(&date.days, &date.months, day_in_month, day_in_month);
	check_ovf_to_date(&date.months, &date.years, 12, 12);
	day_in_month = get_quan_days(date.months, date.years);
	check_ovf_to_date(&date.days, &date.months, day_in_month, day_in_month);
	return (date);
}

static void					push_buf(int date, unsigned char sym)
{
	size_t					len;
	unsigned char			*str;

	str = (unsigned char *)ft_itoa(date);
	len = ft_strlen((const char *)str);
	work_buf(str, len);
	if (sym)
		work_buf(&sym, 1);
	ft_ustrdel(&str);
}

static void					work_iso(t_date date)
{
	int						iso_years;

	if ((iso_years = (4 - ft_size_num(date.years))) > 0)
		memset_buf('0', iso_years);
	push_buf(date.years, '-');
	push_buf_sym_time(date.months, '0');
	push_buf(date.months, '-');
	push_buf_sym_time(date.days, '0');
	push_buf(date.days, 'T');
	push_buf_sym_time(date.hours, '0');
	push_buf(date.hours, ':');
	push_buf_sym_time(date.min, '0');
	push_buf(date.min, 0);
	write_buf_and_clean(WRITE_BUF);
}

void						date_to_str(va_list format)
{
	unsigned long long int	num_date;
	t_date					date;

	num_date = va_arg(format, unsigned long long int);
	date = get_date(num_date);
	date = work_date(date);
	work_iso(date);
}
