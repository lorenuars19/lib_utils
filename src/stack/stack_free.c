/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 20:32:46 by lorenuar          #+#    #+#             */
/*   Updated: 2021/06/21 17:04:49 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lib_stack.h"

/*
** Free the whole stack
*/

void	stack_free(t_stack *stack)
{
	free(stack->data);
	stack->data = NULL;
	stack->size = 0;
	stack->max_siz = 0;
}
