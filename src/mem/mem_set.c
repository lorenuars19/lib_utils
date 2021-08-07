/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 17:16:28 by lorenuar          #+#    #+#             */
/*   Updated: 2021/08/07 17:34:42 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mem.h"

void	*mem_set(void *ptr, int dat, long len)
{
	t_mem	*tmp;

	tmp = (t_mem *)ptr;
	while (tmp && len > 0)
		tmp[--len] = dat;
	return (ptr);
}
