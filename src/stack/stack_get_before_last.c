/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_get_before_last.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 13:03:14 by lorenuar          #+#    #+#             */
/*   Updated: 2021/03/09 21:34:17 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

/*
** Returns the node before the last one on the stack
*/

t_stack	*stack_get_before_last(t_stack *stack)
{
	if (!(stack))
		return (NULL);
	while (stack && stack->next && stack->next->next)
	{
		stack = stack->next;
	}
	return (stack);
}
