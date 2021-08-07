/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nst_from.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:08:25 by lorenuar          #+#    #+#             */
/*   Updated: 2021/06/24 16:52:10 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_nst.h"
#include "lib_chr.h"
#include "lib_str.h"

/*
** Parse Args and strings to make a new nst
** First element is on top
*/

int	nst_from_args(int argc, char *argv[], t_nst *a, int offs)
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
				if (nst_push_back(a, nbr))
					return (error_put(1, E_SFA));
			}
			while (str && *str && is_wsp(*str))
				str++;
			if (str && *str && !is_digit_sign(*str))
				return (error_put(1, "nst_from_args : INPUT non-numeric"));
		}
		i++;
	}
	return (0);
}

/*
** Parse String to make a new nst
** First element is on top
*/

int	nst_from_str(char *str, t_nst *a)
{
	long	nbr;

	while (str && *str)
	{
		nbr = str_eat_nbr(&str);
		if (str && (is_wsp(*str) || !*str))
		{
			if (nst_push_back(a, nbr))
				return (error_put(1, E_SFS));
		}
		while (str && *str && (is_wsp(*str)))
			str++;
		if (str && *str && !is_digit_sign(*str))
			return (error_put(1, "nst_from_str : INPUT non-numeric"));
	}
	return (0);
}
