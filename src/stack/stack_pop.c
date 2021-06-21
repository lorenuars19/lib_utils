/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 20:32:46 by lorenuar          #+#    #+#             */
/*   Updated: 2021/06/21 17:04:42 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_stack.h"

/*
** Pop the node on top of the stack
*/

void	stack_pop(t_stack *stack)
{
	stack->size--;
}
