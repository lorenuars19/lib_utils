/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 13:02:46 by lorenuar          #+#    #+#             */
/*   Updated: 2021/03/09 22:27:12 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

/*
** Pushes the node on top of the stack
*/

t_stack	*stack_push(t_stack **stack, t_stack *new)
{
	if (!stack || !*stack || !new)
		return (NULL);
	new->next = *stack;
	*stack = new;
	return (new);
}

/*
** Pushes a new node containing data
*/

t_stack	*stack_push_data(t_stack **stack, ssize_t data)
{
	t_stack	*new;

	new = stack_new(data);
	if (!new)
		return (NULL);
	new->next = *stack;
	*stack = new;
	return (new);
}
