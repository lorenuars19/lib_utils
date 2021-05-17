/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_dupli.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 17:34:51 by lorenuar          #+#    #+#             */
/*   Updated: 2021/05/17 22:09:48 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lib_str.h"

char	*str_dupli(const char *to_copy)
{
	char	*new;
	int		i;

	i = 0;
	new = malloc((str_len((const char *)to_copy) + 1) * sizeof(char));
	if (!(new))
		return (NULL);
	while (to_copy && *to_copy)
		new[i++] = *to_copy++;
	new[i] = '\0';
	return (new);
}
