/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_digit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 17:43:27 by lorenuar          #+#    #+#             */
/*   Updated: 2021/05/17 21:22:08 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_chr.h"

int	is_digit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_digit_sign(int c)
{
	if ((c >= '0' && c <= '9') || c == '-' || c == '+')
		return (1);
	return (0);
}
