/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 20:32:46 by lorenuar          #+#    #+#             */
/*   Updated: 2021/06/24 18:30:11 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lib_stack.h"

# include <debug_utils.h>

/*
** Free the whole stack
*/

void	stack_free(t_stack *stack)
{
	if (stack && stack->dat)
	{
DBM(stack_free, stack, stack->dat)
		free(stack->dat);
		stack->dat = NULL;
		stack->siz = 0;
		stack->max_siz = 0;
	}
}
