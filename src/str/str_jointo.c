/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_jointo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 17:22:59 by lorenuar          #+#    #+#             */
/*   Updated: 2021/03/08 18:15:38 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

char	*str_jointo(char *s1, char *s2, char **tofree)
{
	char	*a;
	size_t	sl1;
	size_t	sl2;
	size_t	i;

	a = NULL;
	sl1 = str_has(s1, '\0');
	sl2 = str_has(s2, '\0');
	a = (char *)malloc((sl1 + sl2 + 1) * sizeof(char));
	if (!(a))
	{
		if (tofree && *tofree)
			free(*tofree);
		return (NULL);
	}
	i = 0;
	while (sl1 && s1 && *s1)
		a[i++] = *s1++;
	while (sl2 && s2 && *s2)
		a[i++] = *s2++;
	a[i] = '\0';
	if (tofree && *tofree)
		free(*tofree);
	return (a);
}
