/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_cmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 17:26:41 by lorenuar          #+#    #+#             */
/*   Updated: 2021/07/30 13:46:39 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_str.h"

int	str_cmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1 && s2 && s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	if (s1 && s2 && s1[i] && s2[i] && s1[i] == s2[i])
	{
		return (0);
	}
	if (s1 && s2)
	{
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return ((unsigned char *)s1 - (unsigned char *)s2);
}

int	str_cmp_n(const char *s1, const char *s2, size_t size)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i <= size)
	{
		i++;
	}
	if (i == size)
	{
		return (0);
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
