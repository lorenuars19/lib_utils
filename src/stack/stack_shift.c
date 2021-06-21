/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_shift.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 17:13:29 by lorenuar          #+#    #+#             */
/*   Updated: 2021/06/21 17:21:09 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_stack.h"

int	stack_shift(t_stack *stack)
{
	long	i;
	long	tmp;

	stack->size++;
	if (!stack_new_resize(stack))
		return (error_put(1, "stack_shift : stack_new_resize() NULL data"));

	i = stack->size;
	while (stack->data && i < stack->size + 1 && i >= 0)
	{
		stack->data[i + 1] = stack->data[i];
		i--;
	}



}
