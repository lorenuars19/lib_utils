/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 20:38:47 by lorenuar          #+#    #+#             */
/*   Updated: 2021/03/18 10:25:11 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

/*
** Shift UP the whole stack
** the first node becomes the last
*/

int	stack_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return (1);
	tmp = *stack;
	*stack = (*stack)->next;
	last = stack_get_last(*stack);
	last->next = tmp;
	tmp->next = NULL;
	return (0);
}

/*
** Shift DOWN the whole stack
** the last node becomes first
*/

int	stack_rev_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*before_last;

	if (!stack || !*stack || !(*stack)->next)
		return (1);
	before_last = stack_get_before_last(*stack);
	tmp = before_last->next;
	before_last->next = NULL;
	tmp->next = *stack;
	*stack = tmp;
	return (0);
}
