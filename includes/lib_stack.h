/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_stack.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 15:05:51 by lorenuar          #+#    #+#             */
/*   Updated: 2021/05/17 22:14:44 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_STACK_H
# define LIB_STACK_H

# include <unistd.h>

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

#endif
