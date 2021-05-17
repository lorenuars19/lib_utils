/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 20:32:46 by lorenuar          #+#    #+#             */
/*   Updated: 2021/03/09 22:19:21 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

/*
** Pop the node on top of the stack
*/

void	stack_pop(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack)
		return ;
	tmp = *stack;
	(*stack) = (*stack)->next;
	free(tmp);
}
