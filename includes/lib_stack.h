/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_stack.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 15:05:51 by lorenuar          #+#    #+#             */
/*   Updated: 2021/06/21 17:35:04 by lorenuar         ###   ########.fr       */
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

#define	INIT_SIZ 2
#define SIZ_MULT 1.5

typedef struct s_stack
{
	long	*data;
	long	size;
	long	max_siz;
}			t_stack;

int		stack_new_resize(t_stack *stack);
int		stack_push(t_stack *stack, long data);
int		stack_push_back(t_stack *stack, long data);

void	stack_pop(t_stack *stack);
void	stack_free(t_stack *stack);

size_t	stack_get_size(t_stack *stack);

int		stack_from_args(int argc, char *argv[], t_stack *a);
int		stack_from_str(char *str, t_stack *a);


int		stack_swap(t_stack **stack);
int		stack_rotate(t_stack **stack);
int		stack_rev_rotate(t_stack **stack);

#endif
