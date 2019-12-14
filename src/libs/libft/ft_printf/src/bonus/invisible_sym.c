/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invisible_sym.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:02:39 by cormund           #+#    #+#             */
/*   Updated: 2019/07/19 14:42:46 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			before_11(unsigned char sym)
{
	if (sym == 0)
		work_buf((unsigned char *)"nul", 3);
	else if (sym == 1)
		work_buf((unsigned char *)"soh", 3);
	else if (sym == 2)
		work_buf((unsigned char *)"stx", 3);
	else if (sym == 3)
		work_buf((unsigned char *)"etx", 3);
	else if (sym == 4)
		work_buf((unsigned char *)"eot", 3);
	else if (sym == 5)
		work_buf((unsigned char *)"enq", 3);
	else if (sym == 6)
		work_buf((unsigned char *)"ack", 3);
	else if (sym == 7)
		work_buf((unsigned char *)"bel", 3);
	else if (sym == 8)
		work_buf((unsigned char *)"bs", 2);
	else if (sym == 9)
		work_buf((unsigned char *)"ht", 2);
	else if (sym == 10)
		work_buf((unsigned char *)"nl", 2);
	else if (sym == 11)
		work_buf((unsigned char *)"vt", 2);
}

static void			before_23(unsigned char sym)
{
	if (sym == 12)
		work_buf((unsigned char *)"np", 2);
	else if (sym == 13)
		work_buf((unsigned char *)"cr", 2);
	else if (sym == 14)
		work_buf((unsigned char *)"so", 2);
	else if (sym == 15)
		work_buf((unsigned char *)"si", 2);
	else if (sym == 16)
		work_buf((unsigned char *)"dle", 3);
	else if (sym == 17)
		work_buf((unsigned char *)"dc1", 3);
	else if (sym == 18)
		work_buf((unsigned char *)"dc2", 3);
	else if (sym == 19)
		work_buf((unsigned char *)"dc3", 3);
	else if (sym == 20)
		work_buf((unsigned char *)"dc4", 2);
	else if (sym == 21)
		work_buf((unsigned char *)"nak", 2);
	else if (sym == 22)
		work_buf((unsigned char *)"syn", 3);
	else if (sym == 23)
		work_buf((unsigned char *)"etb", 3);
}

static void			before_32(unsigned char sym)
{
	if (sym == 24)
		work_buf((unsigned char *)"can", 3);
	else if (sym == 25)
		work_buf((unsigned char *)"em", 2);
	else if (sym == 26)
		work_buf((unsigned char *)"sub", 3);
	else if (sym == 27)
		work_buf((unsigned char *)"esc", 3);
	else if (sym == 28)
		work_buf((unsigned char *)"fs", 2);
	else if (sym == 29)
		work_buf((unsigned char *)"gs", 2);
	else if (sym == 30)
		work_buf((unsigned char *)"rs", 2);
	else if (sym == 31)
		work_buf((unsigned char *)"us", 2);
	else if (sym == 32)
		work_buf((unsigned char *)"sp", 2);
}

void				invisible_sym(va_list format)
{
	unsigned char	sym;

	sym = va_arg(format, int);
	if (sym < 12)
		before_11(sym);
	else if (sym > 11 && sym < 24)
		before_23(sym);
	else if (sym > 23 && sym < 33)
		before_32(sym);
	else
		work_buf(&sym, 1);
}
