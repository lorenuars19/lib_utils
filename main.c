/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:52:44 by lorenuar          #+#    #+#             */
/*   Updated: 2021/06/21 17:38:35 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <debug_utils.h>

#include "./includes/libutils.h"

int main(void)
{
	int 	i;
	t_stack stack;



	stack = (t_stack){NULL, 0, 0};

	i = 0;
	while (i < 10000000)
	{
		if (stack_push(&stack, i))
			return(1);


DB(&stack, stack.size, stack.max_siz, stack.data, i, stack.data[i]);
	i++;
	}
	stack_free(&stack);
	return (0);


}
