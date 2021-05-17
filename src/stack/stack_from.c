/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_from.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:08:25 by lorenuar          #+#    #+#             */
/*   Updated: 2021/05/17 22:27:37 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_stack.h"
#include "lib_chr.h"
#include "lib_str.h"


/*
** Parse Args and strings to make a new stack
** First element is on top
*/

t_stack	*stack_from_args(int argc, char *argv[], t_stack **a)
{
	ssize_t	nbr;
	char	*str;
	int		i;

	i = 1;
	while (i < argc)
	{
		str = argv[i];
		while (str && *str)
		{
			nbr = str_eat_nbr(&str);
			if (str && (is_wsp(*str) || !*str))
			{
				if (!stack_push_back_data(a, nbr))
					return (NULL);
			}
			while (str && *str && !is_digit_sign(*str))
				str++;
		}
		i++;
	}
	return (*a);
}

/*
** Parse String to make a new stack
** First element is on top
*/

t_stack	*stack_from_str(char *str, t_stack **a)
{
	ssize_t	nbr;

	while (str && *str)
	{
		nbr = str_eat_nbr(&str);
		if (str && (is_wsp(*str) || !*str))
		{
			if (!stack_push_back_data(a, nbr))
				return (NULL);
		}
		while (str && *str && (is_wsp(*str) || !is_digit_sign(*str)))
			str++;
	}
	return (*a);
}
