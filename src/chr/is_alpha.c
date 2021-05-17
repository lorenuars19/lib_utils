/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_alpha.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 17:43:27 by lorenuar          #+#    #+#             */
/*   Updated: 2021/05/17 21:37:01 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_chr.h"

int	is_alpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

int	is_alpha_upper(int c)
{
	if ((c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

int	is_alpha_lower(int c)
{
	if ((c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}
