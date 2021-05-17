/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_eat_nbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 18:00:31 by lorenuar          #+#    #+#             */
/*   Updated: 2021/05/17 22:08:12 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "lib_str.h"
#include "lib_nbr.h"
#include "lib_chr.h"

static ssize_t	ret_eat_nbr(ssize_t num, char sign)
{
	if (num > LONG_MAX)
	{
		if (sign == 1)
			return (-1);
		else if (sign == -1)
			return (0);
	}
	if (sign == 1)
		return (num);
	else if (sign == -1)
		return (-num);
	return (0);
}

ssize_t	str_eat_nbr(char **f)
{
	ssize_t		num;
	char		sign;

	num = 0;
	sign = 1;
	while ((f && *f && is_wsp(**f)))
		(*f)++;
	while (f && *f && (**f == '-' || **f == '+'))
	{
		if (f && *f && **f == '-')
			sign = -1;
		(*f)++;
	}
	while (f && *f && **f >= '0' && **f <= '9')
	{
		num = (num * BASE_DEFAULT) + (**f - '0');
		(*f)++;
	}
	return (ret_eat_nbr(num, sign));
}
