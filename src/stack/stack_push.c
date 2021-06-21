/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 13:02:46 by lorenuar          #+#    #+#             */
/*   Updated: 2021/06/21 17:32:28 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_stack.h"

int	stack_push(t_stack *stack, long data)
{
	if (stack_new_resize(stack))
		return (error_put(1, "stack_push : stack_new_resize() NULL data"));

	stack->data[stack->size] = data;
	stack->size++;

	return (0);
}
