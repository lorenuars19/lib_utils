/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_new_resize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 13:03:14 by lorenuar          #+#    #+#             */
/*   Updated: 2021/06/21 17:31:20 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lib_stack.h"

int	sub_stack_resize(t_stack *stack)
{
	long	i;
	long	*copy;

	copy = malloc(sizeof(long) * stack->size * SIZ_MULT);
	if (!copy)
		return (error_put(1, "sub_stack_resize : copy NULL"));
	i = 0;
	while (i < stack->size)
	{
		copy[i] = stack->data[i];
		i++;
	}
	free(stack->data);
	stack->data = copy;
	stack->max_siz = stack->max_siz * SIZ_MULT;
	return (0);
}

int	stack_new_resize(t_stack *stack)
{
	if (stack->data == NULL)
	{
		stack->max_siz = INIT_SIZ;
		stack->size = 0;
		stack->data = malloc(sizeof(long) * stack->max_siz);
		if (!stack->data)
			return (error_put(1, "stack_new_resize : stack->data NULL"));
	}
	else if (stack->size >= stack->max_siz)
	{
		if (sub_stack_resize(stack))
		{
			stack_free(stack);
			return (1);
		}
	}
	return (0);
}
