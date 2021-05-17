/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_skipto.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 17:36:23 by lorenuar          #+#    #+#             */
/*   Updated: 2021/03/08 18:15:05 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

size_t	str_skipto(char **str, char c)
{
	size_t	skipped;

	skipped = 1;
	while (str && *str && **str)
	{
		if (c == **str)
		{
			*str = *str + 1;
			return (skipped);
		}
		*str = *str + 1;
		skipped++;
	}
	return (0);
}
