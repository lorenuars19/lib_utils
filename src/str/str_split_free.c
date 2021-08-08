/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_split_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 18:22:05 by lorenuar          #+#    #+#             */
/*   Updated: 2021/08/08 14:54:02 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_str.h"
#include <stdlib.h>

void	tab_free(char ***input)
{
	char	**tab;
	int		i;

	tab = *input;
	i = 0;
	while (tab && tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(*input);
	*input = NULL;
}
