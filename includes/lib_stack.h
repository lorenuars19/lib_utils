/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_stack.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 15:05:51 by lorenuar          #+#    #+#             */
/*   Updated: 2021/06/21 21:27:54 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_STACK_H
# define LIB_STACK_H
# include "lib_io.h"
# include <unistd.h>

#include <debug_utils.h>

/*
** stack
*/

#define	STACK_INIT_SIZ 2
#define STACK_SIZ_MULT 1.5

typedef struct s_stack
{
	long	*dat;
	long	siz;
	long	max_siz;
}			t_stack;

int		stack_new_resize(t_stack *stack);
int		stack_push(t_stack *stack, long data);
int		stack_push_back(t_stack *stack, long data);

int		stack_shift_down(t_stack *stack);
int		stack_shift_up(t_stack *stack);

int		stack_pop(t_stack *stack);
int		stack_pop_back(t_stack *stack);

void	stack_free(t_stack *stack);

size_t	stack_get_size(t_stack *stack);

int		stack_from_args(int argc, char *argv[], t_stack *a);
int		stack_from_str(char *str, t_stack *a);


int		stack_swap(t_stack *stack);
int		stack_rotate(t_stack *stack);
int		stack_rev_rotate(t_stack *stack);

# define E_SFA "stack_from_args : stack_push_back()"
# define E_SFS "stack_from_str : stack_push_back()"

#endif
