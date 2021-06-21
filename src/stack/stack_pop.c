/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 20:32:46 by lorenuar          #+#    #+#             */
/*   Updated: 2021/06/21 21:27:30 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_stack.h"

/*
** Pop the node on top of the stack
*/

int	stack_pop(t_stack *stack)
{
	if (stack_shift_up(*&stack))
		return(error_put(1, "stack_pop : stack_shift_up()"));
}

int	stack_pop_back(t_stack *stack)
{
	stack->siz--;
	return (0);
}
