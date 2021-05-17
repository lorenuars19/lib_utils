/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 15:05:33 by lorenuar          #+#    #+#             */
/*   Updated: 2021/04/10 01:17:15 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

size_t	str_len(const char *str)
{
	size_t	len;

	len = 0;
	while (str && str[len])
		len++;
	return (len);
}
