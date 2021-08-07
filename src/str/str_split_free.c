/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_split_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 18:22:05 by lorenuar          #+#    #+#             */
/*   Updated: 2021/08/07 23:43:41 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_str.h"
#include <stdlib.h>

void	tab_free(char ***tab)
{
	int	i;

	i = 0;
	while (tab && *tab && *tab[i])
	{
		free(*tab[i]);
	}
	free(*tab);
	*tab = NULL;
}
