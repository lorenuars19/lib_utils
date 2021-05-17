/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 13:02:46 by lorenuar          #+#    #+#             */
/*   Updated: 2021/03/17 18:30:07 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

/*
** Pushes the node at the bottom of the stack
*/

t_stack	*stack_push_back(t_stack **stack, t_stack *new)
{
	t_stack	*tmp;

	if (!stack || !*stack || !new)
		return (NULL);
	if (stack && !*stack)
	{
		*stack = new;
		return (new);
	}
	tmp = *stack;
	while (new && tmp && tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = new;
	return (new);
}

/*
** Pushes a new node containing data
*/

t_stack	*stack_push_back_data(t_stack **stack, ssize_t data)
{
	t_stack	*tmp;
	t_stack	*new;

	new = stack_new(data);
	if (!new)
		return (NULL);
	if (stack && !*stack)
	{
		*stack = new;
		return (new);
	}
	tmp = *stack;
	while (stack && new && tmp && tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = new;
	return (new);
}
