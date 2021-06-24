/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_new_resize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 13:03:14 by lorenuar          #+#    #+#             */
/*   Updated: 2021/06/24 17:46:11 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lib_stack.h"

#        include <stdio.h> //TODO REMOVE BEFORE PUSH

int	sub_stack_resize(t_stack *stack)
{
	long	i;
	long	*copy;

	long long		siz;

	if (!stack)
	{
		return (error_put(1, "sub_stack_resize : stack NULL"));
	}

	siz = sizeof(long) * stack->siz * STACK_SIZ_MULT;

dprintf(2, "\n\033[32;1m===== siz %lld stack->siz %ld\033[0m\n", siz, stack->siz);

	copy = malloc(siz);
	if (!copy)
	{
		return (error_put(1, "sub_stack_resize : copy NULL"));
	}
	i = 0;
	while (stack && stack->dat && i < stack->siz)
	{

dprintf(2, "\ni %ld Copy[i %ld] <%p> stack->dat[i %ld] <%p>\n", i, i, (void*)copy + (i * sizeof(copy[0])), i, (void*)stack->dat + (i * sizeof(stack->dat[0])));

		copy[i] = stack->dat[i];
		i++;
	}

dprintf(2, "\n\nA stack %p, ->dat %p\n", stack, stack->dat);

	if (stack && stack->dat)
	{
		// free(stack->dat);
	}
	stack->dat = NULL;
	stack->dat = copy;
dprintf(2, "B stack %p, ->dat %p\n", stack, stack->dat);
	stack->max_siz = stack->max_siz * STACK_SIZ_MULT;
	return (0);
}

int	stack_new_resize(t_stack *stack)
{
	if (!stack)
		return (error_put(1, "stack_new_resize : NULL stack"));
	if (stack->dat == NULL)
	{
		stack->max_siz = STACK_INIT_SIZ;
		stack->siz = 0;
		stack->dat = malloc(sizeof(long) * stack->max_siz);
		if (!stack->dat)
			return (error_put(1, "stack_new_resize : stack->data NULL"));
	}
	else if (stack->siz >= stack->max_siz)
	{
		if (sub_stack_resize(stack))
		{
			stack_free(stack);
			return (1);
		}
	}
	return (0);
}
