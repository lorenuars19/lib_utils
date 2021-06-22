/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_from.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:08:25 by lorenuar          #+#    #+#             */
/*   Updated: 2021/06/22 17:43:04 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_stack.h"
#include "lib_chr.h"
#include "lib_str.h"

/*
** Parse Args and strings to make a new stack
** First element is on top
*/

int	stack_from_args(int argc, char *argv[], t_stack *a, int offs)
{
	long	nbr;
	char	*str;
	int		i;

	i = offs;
	while (i < argc)
	{
		str = argv[i];
		while (str && *str)
		{
			nbr = str_eat_nbr(&str);
			if (str && (is_wsp(*str) || !*str))
			{
				if (stack_push_back(a, nbr))
					return (error_put(1, E_SFA));
			}
			if (str && *str && !(is_wsp(*str) || is_digit_sign(*str)))
				return (error_put(1, "stack_from_args : INPUT non-numeric"));
			while (str && *str && is_wsp(*str))
				str++;
		}
		i++;
	}
	return (0);
}

/*
** Parse String to make a new stack
** First element is on top
*/

int	stack_from_str(char *str, t_stack *a)
{
	long	nbr;

	while (str && *str)
	{
		nbr = str_eat_nbr(&str);
		if (str && (is_wsp(*str) || !*str))
		{
			if (stack_push_back(a, nbr))
				return (error_put(1, E_SFS));
		}
		if (str && *str && (!is_wsp(*str) || !is_digit_sign(*str)))
			return (error_put(1, "stack_from_str : INPUT non-numeric"));
		while (str && *str && (is_wsp(*str)))
			str++;
	}
	return (0);
}
