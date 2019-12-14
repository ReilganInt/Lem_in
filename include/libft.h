/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 12:17:44 by ksharlen          #+#    #+#             */
/*   Updated: 2019/12/09 12:58:03 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <assert.h>
# include <errno.h>
# include <limits.h>
# include "ft_printf.h"

# define MAXLLI 9223372036854775807
# define FD_MAX 7198
# define BUFF_SIZE 4

# define NUM_MOD(x)			((x) = (x > 0) ? x : -(x))
# define CHECK_MOD(x)		((x) > 0) ? (x) : -(x)
# define SET_BIT(val, num)	((val) = ((val) | (1 << (num))))
# define NUM_CMP(a, b) 		((((a) ^ (b)) == 0) ? 0 : 1)
# define FT_MIN(X, Y)		(((X) < (Y)) ? (X) : (Y))
# define FT_MAX(X, Y)		(((X) > (Y)) ? (X) : (Y))

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
size_t				ft_strnlen(const char *str, int n);
char				*ft_strdup(const char *s1);
char				*ft_strndup(const char *s1, size_t n);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
		size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *nptr);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isupper(int c);
int					ft_islower(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
int					**ft_memalloc_int_mas(ssize_t y, ssize_t x);
char				**ft_memalloc_char_2xmas(ssize_t y, ssize_t x);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_str_chr_clr(char *s, char c);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strcut(char *s, char c);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_isspace(int c);
ssize_t				ft_pow(int n, int level);
int					ft_revers(int n);
void				ft_lstadd_end(t_list **begin_list, t_list *elem);
int					get_next_line(const int fd, char **line);
void				ft_lstfreeone(void *content, size_t content_size);
t_list				*ft_lstelem(t_list *begin_list,
	size_t index, size_t lst_size);
size_t				ft_lstsize(t_list *beg);
ssize_t				ft_arrfind(int *arr, int data, size_t size);
t_list				*ft_lstreplace(t_list **rep, void *content,
	size_t content_size);
char				*ft_strnjoin(const char *str1, const char *str2,
	size_t num_str1, size_t num_str2);
void				*ft_memsub(const void *s, unsigned int start, size_t len);
void				*ft_memnjoin(const void *s1, const void *s2,
	size_t num1, size_t num2);
size_t				ft_memnlen(const void *s, int n, size_t size);
int					ft_ischar(const char *str, int c);
int					ft_isstr(const char *str, const char *check_symbals);
int					ft_memischar(const char *str, int n, size_t size);
int					ft_memisstr(const char *str,
	const char *chek_format, size_t size);
void				ft_swap(int *a, int *b);
size_t				ft_size_num(int a);
unsigned			ft_set_bit(unsigned val, unsigned num);
unsigned			ft_set_bits(unsigned val, unsigned bits, unsigned num);
unsigned			ft_bitscpy(unsigned value, unsigned inval, unsigned num);
size_t				ft_wcslen(const wchar_t *str);
void				ft_ustrdel(unsigned char **str);
char				*ft_skipfirst(char *str, int sym);
void				ft_free_2x_mas(void **mas);
char				*gnl(int fd);
void				error(const char *error_msg);

#endif
