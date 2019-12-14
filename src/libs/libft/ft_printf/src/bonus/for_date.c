/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_date.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:00:01 by cormund           #+#    #+#             */
/*   Updated: 2019/07/19 12:00:02 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_ovf_to_time(int *num, int *num1, int ovf, int check)
{
	if (*num > check)
	{
		*num1 += *num / ovf;
		*num %= ovf;
	}
}

void	check_ovf_to_date(int *num, int *num1, int ovf, int check)
{
	if (*num > check)
	{
		if (!((*num) % check))
			*num = *num + 1;
		*num1 += *num / ovf;
		*num %= ovf;
	}
}

void	push_buf_sym_time(int num, unsigned char sym)
{
	if (num < 10)
		work_buf(&sym, 1);
}

int		get_leap(int years)
{
	int day_in_month;

	if (!(years % 400))
		day_in_month = 29;
	else if (!(years % 100))
		day_in_month = 28;
	else if (!(years % 4))
		day_in_month = 29;
	else
		day_in_month = 28;
	return (day_in_month);
}

int		get_quan_days(int month, int years)
{
	if (month == 1 || month == 3 || month == 5 || month == 7 ||
		month == 8 || month == 10 || month == 12)
		return (31);
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		return (30);
	else if (month == 2)
		return (get_leap(years));
	else
		return (0);
}
