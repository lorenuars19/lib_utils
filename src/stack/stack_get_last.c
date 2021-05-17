/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_get_last.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 13:03:14 by lorenuar          #+#    #+#             */
/*   Updated: 2021/03/09 21:37:52 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

/*
** Returns last node on the stack
*/

t_stack	*stack_get_last(t_stack *stack)
{
	if (!(stack))
		return (NULL);
	while (stack && stack->next)
	{
		stack = stack->next;
	}
	return (stack);
}

/*
**	Returns n before las node on the stack
*/

t_stack	*stack_get_last_n(t_stack *stack, size_t n)
{
	size_t	i;
	size_t	max;

	if (!(stack))
		return (NULL);
	i = 0;
	max = stack_get_size(stack);
	if (n < max)
		max -= n;
	while (i < max && stack && stack->next)
	{
		stack = stack->next;
		i++;
	}
	return (stack);
}
