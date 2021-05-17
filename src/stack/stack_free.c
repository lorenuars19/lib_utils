/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 20:32:46 by lorenuar          #+#    #+#             */
/*   Updated: 2021/03/09 23:02:59 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

/*
** Free the whole stack
*/

void	stack_free(t_stack **stack)
{
	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		stack_pop(stack);
	}
}
