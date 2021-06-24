/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                   stack->siz++;             +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 20:32:46 by lorenuar          #+#    #+#             */
/*   Updated: 2021/06/21 21:49:17 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_stack.h"

/*
** Pop the node on top of the stack
*/

int	stack_pop(t_stack *stack)
{
	if (stack_shift_up(*&stack))
		return (error_put(1, "stack_pop : stack_shift_up()"));
	return (0);
}

int	stack_pop_back(t_stack *stack)
{
	stack->i--;
	stack->siz = stack->i + 1;
	return (0);
}
