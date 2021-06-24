/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 20:38:47 by lorenuar          #+#    #+#             */
/*   Updated: 2021/06/24 18:57:32 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_stack.h"

int	stack_rotate(t_stack *stack)
{
	long	tmp;

	if (!stack)
		return (error_put(1, "stack_rotate : NULL stack"));
	tmp = stack->dat[0];
	if (stack_pop(stack))
		return (error_put(1, "stack_rotate : stack_pop()"));
	if (stack_push_back(stack, tmp))
		return (error_put(1, "stack_rotate : stack_push_back()"));
	return (0);
}

int	stack_rev_rotate(t_stack *stack)
{
	long	tmp;

	if (!stack)
		return (error_put(1, "stack_rev_rotate : NULL stack"));
	tmp = stack->dat[stack->siz - 1];
	if (stack_pop_back(stack))
		return (error_put(1, "stack_rev_rotate : stack_pop_back()"));
	if (stack_push(stack, tmp))
		return (error_put(1, "stack_rev_rotate : stack_push()"));
	return (0);
}
