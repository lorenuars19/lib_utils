/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnst_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 20:32:46 by lorenuar          #+#    #+#             */
/*   Updated: 2021/06/24 18:07:27 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lib_gnst.h"

/*
** Free the whole gnst
*/

void	gnst_free(t_gnst *gnst)
{
	if (gnst && gnst->dat)
	{
		free(gnst->dat);
		gnst->dat = NULL;
		gnst->siz = 0;
		gnst->max_siz = 0;
	}
}
