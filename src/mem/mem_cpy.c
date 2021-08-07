/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_cpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 17:27:48 by lorenuar          #+#    #+#             */
/*   Updated: 2021/08/07 17:32:29 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mem.h"

void	*mem_cpy(void *dst, const void *src, long size)
{
	long	i;

	i = 0;
	if (dst == src)
		return (dst);
	while (dst && src && i < size)
	{
		(*(t_mem *)&dst[i]) = (*(t_mem *)&src[i]);
		i++;
	}
	return (dst);
}
