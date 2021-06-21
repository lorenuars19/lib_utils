/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:53:01 by lorenuar          #+#    #+#             */
/*   Updated: 2021/06/21 15:24:18 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_math.h"

int	mini(int a, int b)
{
	if (a >= 0)
	{
		if (a < b)
			return (a);
	}
	else
	{
		if (a > b)
			return (a);
	}
	return (b);
}

long	minl(long a, long b)
{
	if (a >= 0)
	{
		if (a < b)
			return (a);
	}
	else
	{
		if (a > b)
			return (a);
	}
	return (b);
}
