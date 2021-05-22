/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 10:09:39 by lorenuar          #+#    #+#             */
/*   Updated: 2021/05/22 22:18:58 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libutils.h"

# define BASE_10 "0123456789"
# define BASE_S_HEX "0123456789abcdef"
# define BASE_HEX "0123456789ABCDEF"
# define OPT_CHARS "0123456789.*-+"

# define APPLE_PTR_NULL "0x0"
# define LINUX_PTR_NULL "(nil)"

# ifdef __APPLE__
#  define PTR_NULL APPLE_PTR_NULL
#  define PTR_DOT_NULL "0x"
# else
#  define PTR_NULL LINUX_PTR_NULL
#  define PTR_DOT_NULL LINUX_PTR_NULL
# endif

typedef char	t_bool;

enum			e_bool
{
	false,
	true
};

typedef struct s_base
{
	size_t	bse;
	char	*chr;
}			t_base;

typedef struct s_nstat
{
	ssize_t	num;
	ssize_t	len;
	t_base	bse;
	int		neg;
}			t_nstat;

typedef struct s_opt
{
	int		fd;
	int		uns;
	int		zr;
	int		spa;
	int		pls;
	int		alt;
	int		neg;
	int		dot;
	ssize_t	fw;
	ssize_t	pr;
	char	cv;
}			t_opt;

int		ft_printf(char *fmt, ...);
int		ft_printf_fd(int fd, char *fmt, ...);

ssize_t	call_dispatch(va_list args, t_opt opt);

ssize_t	get_opt(va_list args, char **fmt, int fd);
void	sub_get_opts(va_list args, char **fmt, t_opt *opt);

ssize_t	print_nbr(ssize_t num, char *b_chars, t_opt opt);
ssize_t	print_nbr_unsigned(unsigned int num, char *b_chars, t_opt opt);

ssize_t	format_nbr_space(t_opt opt, t_nstat nst, int order);
void	format_nbr_killswitches(t_opt opt, t_nstat nst,
			int order, ssize_t *x);

ssize_t	format_nbr_zero(t_opt opt, t_nstat nst);
ssize_t	format_ptr_space(t_nstat nst, t_opt opt, int order);

ssize_t	print_hex(unsigned int num, char *b_chars, t_opt opt);
ssize_t	print_char(char c, t_opt opt);
ssize_t	print_str(char *s, t_opt opt);
ssize_t	print_ptr(void *ptr, t_opt opt);

ssize_t	put_char(char c, int fd);
ssize_t	n_str(char *s, ssize_t n, size_t len, int fd);
size_t	skip_to(char **fmt, char c);
size_t	hasto(char *s, char c);

ssize_t	read_num(va_list args, char **f);
ssize_t	star_return(va_list args, char **f);
ssize_t	sub_put_nbr(ssize_t num, ssize_t base, char *b_chars, int fd);
size_t	sub_put_nbr_uns(size_t num, size_t base, char *b_chars, int fd);

size_t	num_len(ssize_t num, ssize_t base);
size_t	num_len_unsigned(size_t num, ssize_t base);


#endif
