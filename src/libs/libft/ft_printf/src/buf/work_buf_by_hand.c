/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_buf_by_hand.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 10:56:35 by ksharlen          #+#    #+#             */
/*   Updated: 2019/07/24 12:53:34 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned char		*check_buf(ssize_t size_str)
{
	unsigned char	*buf;

	if (SIZE_BUF >= size_str)
	{
		if (g_spec.size_buf < size_str)
			write_buf_and_clean(WRITE_BUF);
		buf = work_buf(GET_POINT, 0);
		g_spec.size_write += size_str;
		g_spec.size_buf -= size_str;
	}
	else if (!(buf = ft_memalloc(size_str)))
		exit(0);
	return (buf);
}

void				memset_buf(unsigned char sym, int size)
{
	unsigned char	*buf;
	int				ret_check_loc;

	ret_check_loc = check_loc_buf(size);
	if (ret_check_loc == 1)
		write_buf_and_clean(NULL);
	else if (ret_check_loc == -1)
	{
		write_buf_and_clean(NULL);
		buf = (unsigned char *)ft_memalloc(size);
		ft_memset(buf, sym, size);
		g_spec.ret_printf += write(g_spec.fd, buf, size);
		ft_ustrdel(&buf);
		return ;
	}
	buf = work_buf(GET_POINT, 0);
	ft_memset(buf, sym, size);
	g_spec.size_write += size;
	g_spec.size_buf -= size;
}

void				memcpy_buf(void *src, size_t size)
{
	unsigned char	*buf;
	int				ret_check_loc;

	buf = work_buf(GET_POINT, 0);
	ret_check_loc = check_loc_buf(size);
	if (ret_check_loc == 1)
	{
		write_buf_and_clean(NULL);
		work_buf(src, size);
	}
	else if (ret_check_loc == -1)
	{
		write_buf_and_clean(WRITE_BUF);
		g_spec.ret_printf += write(g_spec.fd, src, size);
	}
	else
	{
		ft_memcpy(buf, src, size);
		g_spec.size_write += size;
		g_spec.size_buf -= size;
	}
}
