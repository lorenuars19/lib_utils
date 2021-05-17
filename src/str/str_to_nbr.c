/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 18:00:31 by lorenuar          #+#    #+#             */
/*   Updated: 2021/05/17 22:09:10 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "lib_str.h"
#include "lib_chr.h"
#include "lib_nbr.h"

ssize_t	str_to_nbr(const char *s)
{
	ssize_t	num;
	int		sign;

	num = 0;
	sign = 1;
	while (s && *s && is_wsp(*s))
		s++;
	if (s && *s == '-')
		sign = -1;
	while (s && (*s == '-' || *s == '+'))
		s++;
	while (s && *s >= '0' && *s <= '9')
		num = (num * BASE_DEFAULT) + (*s++ - '0');
	if (num > LONG_MAX)
	{
		if (sign == 1)
			return (-1);
		else
			return (0);
	}
	if (sign == 1)
		return (num);
	else
		return (-num);
	return (0);
}

ssize_t	str_to_nbr_base(const char *s, int base)
{
	ssize_t	num;
	int		sign;

	num = 0;
	sign = 1;
	while (s && *s && is_wsp(*s))
		s++;
	if (s && *s == '-')
		sign = -1;
	while (s && (*s == '-' || *s == '+'))
		s++;
	while (s && *s >= '0' && *s <= '9')
		num = (num * base) + (*s++ - '0');
	if (num > LONG_MAX)
	{
		if (sign == 1)
			return (-1);
		else
			return (0);
	}
	if (sign == 1)
		return (num);
	else
		return (-num);
	return (0);
}
