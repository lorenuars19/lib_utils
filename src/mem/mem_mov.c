/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_mov.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 11:05:34 by lorenuar          #+#    #+#             */
/*   Updated: 2021/08/07 17:39:12 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mem.h"

void	*mem_mov(void *dst, const void *src, long size)
{
	long	i;
	t_mem	*tmp_dst;
	t_mem	*tmp_src;

	tmp_dst = (t_mem *)dst;
	tmp_src = (t_mem *)src;
	if (dst == src)
		return (dst);
	if (src < dst && tmp_dst && tmp_src)
	{
		i = size;
		while (i--)
			tmp_dst[i] = tmp_src[i];
	}
	else if (src > dst && tmp_dst && tmp_src)
	{
		i = 0;
		while (i < size)
			tmp_dst[i++] = *tmp_src++;
	}
	return (dst);
}
