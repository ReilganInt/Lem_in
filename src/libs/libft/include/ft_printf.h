/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 12:15:04 by ksharlen          #+#    #+#             */
/*   Updated: 2019/07/25 14:06:44 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdint.h>
# include <stddef.h>

# define SIZE_BUF			64
# define WRITE_BUF			NULL
# define GET_POINT			WRITE_BUF

/*
**sysNum
*/
# define BIN 				2
# define OCT 				8
# define DECEM				10
# define HEX 				16

/*
**Flags
*/

/*
**HH
*/
# define ZERO				1

/*
**H
*/
# define PLUS				2

/*
**L
*/
# define DASH				4

/*
**LL
*/
# define SPACE				8

/*
**J
*/
# define HASH				16

/*
**Z
*/
# define DOT 				32

/*
**T
*/
# define DEC				64

/*
**big L for double
*/
# define STAR_ACC			128
# define STAR_WITH			256

/*
**Exeptions
*/
# define NUM_INT 			"dDoOxXuUibBp"
# define NUM_DOUBLE 		"fFeEgGaA"
# define NUM_STRING			"sScC"
# define NUM_OTHER 			"nrkv"

# define SIGNED_INT 		"dicCD"
# define UNSIGNED_INT 		"puxXoUbB"

# define UNDEF_BEH			"!\"&()/\\<=>?@[]^_`{}|~"
# define SIZE_MOD			"zjlht"

# define COLOR				"brgypw"
# define COLOR_F			"gih"

# define SUPPORT_INT 		"diouxXn"
# define SUPPORT_FLOAT 		"feEgGaAF"

# define TWO_POW_TWENTY_EIGHT	268435456
# define FIVE_POW_TWENTEEN	244140625

typedef	struct				s_utf
{
	wchar_t					unicode;
	unsigned				bytes;
	wchar_t					utf_sym;
}							t_utf;

typedef struct				s_date
{
	int						min;
	int						hours;
	int						days;
	int						months;
	int						years;
}							t_date;

typedef union				u_uni
{
	long double				num;
	struct
	{
		unsigned long		mantissa:64;
		short int			exp:15;
		unsigned int		sign:1;
	}						bits;
}							t_uni;

typedef struct				s_long
{
	unsigned				*nbr_int;
	unsigned				*nbr_fract;
	unsigned				*nbr_tmp;
	unsigned				*nbr_dot;
	int						len_int;
	int						len_fract;
	int						len_tmp;
	int						e;
}							t_long;

typedef struct				s_spec
{
	int						flags;
	int						width;
	int						accuracy;
	int						mod;
	unsigned char			spec;
	int						ret_printf;
	int						size_buf;
	int						size_write;
	size_t					shift_spec;
	int						size_num;
	int						fd;
}							t_spec;

extern	t_spec				g_spec;

/*
**main function
*/
int							ft_printf(const char *format, ...);
void						work_to_format(const char *format, va_list form);
void						work_spec_form(const char *format, va_list form);

/*
**size function
*/
int							l_format(const int next_symbal);
int							h_format(const int next_symbal);
int							j_z_t_format(const int check_mod);
int							big_l(void);

/*
**format function
*/
void						int_to_str(long long int num);
void						base_to_str(unsigned long long int num);
char						*ptr_to_str(unsigned long long ptr);
void						str_to_str(va_list format);
void						char_to_str(va_list format);
void						double_to_str(va_list format);
void						other_spec(va_list format);
void						not_spec(void);

/*
**Buffer function
*/
unsigned char				*work_buf(const unsigned char *inbuf,
int size_inbuf);
void						write_buf_and_clean(unsigned char *buf);
int							check_loc_buf(int size);
void						memset_buf(unsigned char sym, int size);
void						memcpy_buf(void *src, size_t size);
unsigned char				*check_buf(ssize_t size_str);

/*
**bonus function
*/
int							color_format(const char *string);
void						invisible_sym(va_list format);
void						write_to_file(va_list format);
void						date_to_str(va_list format);
int							get_quan_days(int month, int years);
int							get_leap(int years);
void						push_buf_sym_time(int num, unsigned char sym);
void						check_ovf_to_time(int *num, int *num1,
int ovf, int check);
void						check_ovf_to_date(int *num, int *num1,
int ovf, int check);

/*
**double function
*/
void						long_arithmetic(t_uni real_num, t_long *res);
void						malloc_long(t_uni *real_num, t_long *res);
size_t						size_num_for_long(t_long *res);
int							banker_rounding(unsigned int *nbr, int i, int len);
ssize_t						delete_zero(t_long *res, unsigned int *nbr,\
										ssize_t i);
void						push_double_to_str(unsigned char *buf, t_long *res,\
										size_t size_str, ssize_t size_num);

/*
**UTF-8
*/
unsigned					def_num_bytes(wchar_t unicode);
unsigned					inst_mask(t_utf utf);
t_utf						push_unicode(t_utf utf);
unsigned char				*push_wchar_to_buf(t_utf utf);
t_utf						convert_sym_utf8(wchar_t sym);
unsigned char				*push_wchar_in_char(t_utf utf, unsigned char *str);
unsigned char				*convert_utf8(wchar_t *str, size_t len_utf8);

/*
**other function
*/
int							base_depth(unsigned long long int num, int base);
unsigned char				chr_space_plus_dec(void);
unsigned char				*size_work(unsigned char *str, size_t size_num);
int							ismy(char form);
int							str_size_num(const char *format);
void						select_num_sys(va_list format);
void						work_aw(void);
void						push_wa(unsigned char *inbuf);
void						write_and_free_malloc(unsigned char *buf,
size_t size_str);
int							check_the_entry(const char *def_str,
											const int sym);

#endif
