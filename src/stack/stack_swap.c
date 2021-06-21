/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 20:38:47 by lorenuar          #+#    #+#             */
/*   Updated: 2021/06/21 21:45:34 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_stack.h"

int	stack_swap(t_stack *stack)
{
	long tmp;

	if (!stack)
		return (error_put(1, "stack_swap : NULL stack"));

	if (stack->siz > 1)
	{
		tmp = stack->dat[0];
		stack->dat[0] = stack->dat[1];
		stack->dat[1] = tmp;
	}

	return (0);
}
