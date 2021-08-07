/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_io.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 15:05:51 by lorenuar          #+#    #+#             */
/*   Updated: 2021/08/07 16:12:37 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_IO_H
# define LIB_IO_H

# include <unistd.h>

/*
** ANSI Colors
*/
# define RST "\033[0m"
# define RED "\033[31;1m"
# define GRN "\033[32;1m"
# define YEL "\033[33;1m"
# define BLU "\033[34;1m"
# define MAG "\033[35;1m"
# define CYA "\033[36;1m"
# define WHI "\033[37;1m"

/*
** ANSI Colors Presets
*/
# define ERR "\033[91;1m"

/*
** io
*/

void	put_str(char *str);
void	put_str_nl(char *str);
void	put_str_fd(int fd, char *str);
void	put_str_fd_nl(int fd, char *str);

ssize_t	put_str_times(char *s, ssize_t n, size_t len);
ssize_t	put_str_times_nl(char *s, ssize_t n, size_t len);
ssize_t	put_str_times_fd(int fd, char *s, ssize_t n, size_t len);
ssize_t	put_str_times_fd_nl(int fd, char *s, ssize_t n, size_t len);

void	put_chr(char chr);
void	put_chr_fd(int fd, char chr);

void	*error_ptr_put(char *s);
int		error_put(int ret, char *s);
int		error_sys_put(char *msg);
int		error_printf(int ret, char *fmt, ...);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

int		get_next_line(int fd, char **line);

#endif
