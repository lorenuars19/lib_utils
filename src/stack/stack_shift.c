/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_shift.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 17:13:29 by lorenuar          #+#    #+#             */
/*   Updated: 2021/06/21 21:24:44 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_stack.h"

int	stack_shift_down(t_stack *stack)
{
	long	i;
	long	tmp;

	if (!stack)
		return (error_put(1, "stack_shift : NULL stack"));
	stack->siz++;
	if (stack_new_resize(stack))
		return (error_put(1, "stack_shift : stack_new_resize() NULL data"));

	i = stack->siz - 1;
	while (stack->dat && i < stack->siz && i >= 0)
	{
		stack->dat[i + 1] = stack->dat[i];
		i--;
	}
	return (0);
}

int	stack_shift_up(t_stack *stack)
{
	long	i;
	long	tmp;

	if (!stack)
		return (error_put(1, "stack_shift : NULL stack"));
	stack->siz--;
	if (stack_new_resize(stack))
		return (error_put(1, "stack_shift : stack_new_resize() NULL data"));

	i = 0;
	while (stack->dat && i < stack->siz && i >= 0)
	{
		stack->dat[i] = stack->dat[i + 1];
		i++;
	}
	return (0);
}
