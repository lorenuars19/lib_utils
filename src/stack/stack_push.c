/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 13:02:46 by lorenuar          #+#    #+#             */
/*   Updated: 2021/06/21 21:24:46 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_stack.h"

int	stack_push(t_stack *stack, long data)
{

	if (!stack)
		return (error_put(1, "stack_push : NULL stack"));

	if (stack_shift_down(stack))
		return (1);
	if (stack && stack->dat)
	{
		stack->dat[0] = data;
	}

	return (0);
}
