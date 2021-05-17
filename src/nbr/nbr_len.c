/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 17:30:20 by lorenuar          #+#    #+#             */
/*   Updated: 2021/03/08 18:22:15 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

size_t	nbr_len(ssize_t num)
{
	size_t	len;

	len = 1;
	if (num < 0)
	{
		num = -num;
	}
	while (num > 0)
	{
		num /= BASE_DEFAULT;
		len++;
	}
	return (len);
}

size_t	nbr_len_base(ssize_t num, ssize_t base)
{
	size_t	len;

	len = 1;
	if (num < 0 && base == BASE_DEFAULT)
	{
		num = -num;
	}
	while (num > 0)
	{
		num /= base;
		len++;
	}
	return (len);
}
