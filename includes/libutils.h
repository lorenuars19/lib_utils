/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libutils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 15:05:51 by lorenuar          #+#    #+#             */
/*   Updated: 2021/04/10 01:25:07 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUTILS_H
# define LIBUTILS_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdarg.h>
# include <errno.h>
# include <string.h>
# include <limits.h>

# include "ft_printf.h"

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
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

void	put_str(char *str);
void	put_str_nl(char *str);
void	put_str_fd(int fd, char *str);
void	put_str_fd_nl(int fd, char *str);
ssize_t	put_str_times(char *s, ssize_t n, size_t len);
ssize_t	put_str_times_fd(int fd, char *s, ssize_t n, size_t len);
void	put_chr(char chr);
void	put_chr_fd(int fd, char chr);
void	put_str_fd(int fd, char *str);
int		get_next_line(int fd, char **line);
void	*error_ptr_put(char *s);
int		error_put(int ret, char *s);
int		error_sys_put(int err);

/*
** lists
*/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*lst_new(void *content);

void	lst_add_back(t_list **alst, t_list *new);
void	lst_add_front(t_list **alst, t_list *new);
void	lst_free(t_list **lst, void (*del)(void*));
void	lst_delone(t_list *lst, void (*del)(void*));
void	lst_iter(t_list *lst, void (*f)(void *));

size_t	lst_size(t_list *lst);

t_list	*lst_last(t_list *lst);
t_list	*lst_map(t_list *lst, void *(*f)(void *), void (*del)(void *));
/*
** lists/stack
*/
typedef struct s_stack
{
	ssize_t			data;
	struct s_stack	*next;
}	t_stack;

t_stack	*stack_new(ssize_t data);
t_stack	*stack_push(t_stack **stack, t_stack *new);
t_stack	*stack_push_back(t_stack **stack, t_stack *new);
t_stack	*stack_push_data(t_stack **stack, ssize_t data);
t_stack	*stack_push_back_data(t_stack **stack, ssize_t data);

void	stack_pop(t_stack **stack);
void	stack_free(t_stack **stack);

size_t	stack_get_size(t_stack *stack);

t_stack	*stack_get_last(t_stack *stack);
t_stack	*stack_get_before_last(t_stack *stack);
t_stack	*stack_get_last_n(t_stack *stack, size_t n);

t_stack	*stack_from_args(int argc, char *argv[], t_stack **a);
t_stack	*stack_from_str(char *str, t_stack **a);

int		stack_swap(t_stack **stack);
int		stack_rotate(t_stack **stack);
int		stack_rev_rotate(t_stack **stack);

/*
** nbr
*/
# define BASE_DEFAULT 10
# define BASE_10 "0123456789"
# define BASE_S_HEX "0123456789abcdef"
# define BASE_HEX "0123456789ABCDEF"

ssize_t	put_nbr(ssize_t num);
ssize_t	put_nbr_fd(int fd, ssize_t num);
ssize_t	put_nbr_base(ssize_t num, ssize_t base, char *b_chars);
ssize_t	put_nbr_base_fd(int fd, ssize_t num, ssize_t base, char *b_chars);

size_t	nbr_len(ssize_t num);
size_t	nbr_len_base(ssize_t num, ssize_t base);

char	*nbr_to_str(ssize_t nbr);
char	*nbr_to_str_base(ssize_t nbr, int base, char *b_chars);

/*
** str
*/
size_t	str_len(const char *str);
size_t	str_has(const char *s, char c);
size_t	str_skipto(char **str, char c);

char	*str_jointo(char *s1, char *s2, char **tofree);
char	*str_dupli(const char *to_copy);

int		str_cmp(const char *s1, const char *s2);
int		str_cmp_n(const char *s1, const char *s2, size_t size);
int		is_charset(char c, char *set);

ssize_t	str_to_nbr(const char *s);
ssize_t	str_to_nbr_base(const char *s, int base);

ssize_t	str_eat_nbr(char **f);

/*
** chr
*/
int		is_charset(char c, char *set);
int		is_alnum(int c);
int		is_alpha(int c);
int		is_ascii(int c);
int		is_digit(int c);
int		is_digit_sign(int c);
int		is_print(int c);
int		is_wsp(char c);

#endif
