/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_has.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 17:22:59 by lorenuar          #+#    #+#             */
/*   Updated: 2021/03/08 18:30:52 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

size_t	str_has(const char *s, char c)
{
	size_t	to;

	to = 0;
	while (s && s[to])
	{
		if (s[to] == c)
			return (to + 1);
		to++;
	}
	if (s && s[to] == c)
		return (to + 1);
	return (0);
}
