/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_to_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 17:51:40 by lorenuar          #+#    #+#             */
/*   Updated: 2021/03/08 18:29:07 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

char	*nbr_to_str(ssize_t nbr)
{
	char	*a;
	int		len;
	int		tmp;

	if (nbr == LONG_MIN)
		return (str_dupli("LONG_MIN"));
	tmp = nbr;
	len = nbr_len(nbr);
	a = malloc(sizeof(char) * (len + 1));
	if (!(a))
		return (NULL);
	a[len] = '\0';
	if (nbr < 0)
		nbr *= -1;
	while (len-- > 0)
	{
		a[len] = nbr % BASE_DEFAULT + '0';
		nbr /= BASE_DEFAULT;
	}
	if (tmp < 0)
		a[0] = '-';
	return (a);
}

char	*nbr_to_str_base(ssize_t nbr, int base, char *b_chars)
{
	char		*a;
	int			len;
	int			tmp;

	if (nbr == LONG_MIN)
		return (str_dupli("LONG_MIN"));
	tmp = nbr;
	len = nbr_len_base(nbr, base);
	a = malloc(sizeof(char) * (len + 1));
	if (!(a))
		return (NULL);
	a[len] = '\0';
	if (nbr < 0)
		nbr *= -1;
	while (len-- > 0)
	{
		a[len] = b_chars[nbr % base];
		nbr /= base;
	}
	if (tmp < 0)
		a[0] = '-';
	return (a);
}
