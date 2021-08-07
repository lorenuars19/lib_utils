/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_cpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 17:27:48 by lorenuar          #+#    #+#             */
/*   Updated: 2021/08/07 17:39:27 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mem.h"

void	*mem_cpy(void *dst, const void *src, long size)
{
	long	i;
	t_mem	*tmp_dst;
	t_mem	*tmp_src;

	tmp_dst = (t_mem *)dst;
	tmp_src = (t_mem *)src;
	i = 0;
	if (dst == src)
		return (dst);
	while (dst && src && i < size)
	{
		tmp_dst[i] = tmp_src[i];
		i++;
	}
	return (dst);
}
