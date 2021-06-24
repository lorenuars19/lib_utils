/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_gnst.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 18:09:49 by lorenuar          #+#    #+#             */
/*   Updated: 2021/06/24 18:11:47 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_GNST_H
# define LIB_GNST_H
# include "lib_io.h"
# include <unistd.h>

/*
** gnst
*/

# define gnst_INIT_SIZ 2
# define gnst_SIZ_MULT 2

typedef struct s_generic_stack
{
	void	**dat;
	long	siz;
	long	max_siz;
}			t_gnst;

int		gnst_new_resize(t_gnst *gnst);
int		gnst_push(t_gnst *gnst, void *data);
int		gnst_push_back(t_gnst *gnst, void *data);

int		gnst_shift_down(t_gnst *gnst);
int		gnst_shift_up(t_gnst *gnst);

int		gnst_pop(t_gnst *gnst);
int		gnst_pop_back(t_gnst *gnst);

void	gnst_free(t_gnst *gnst);

size_t	gnst_get_size(t_gnst *gnst);

int		gnst_swap(t_gnst *gnst);
int		gnst_rotate(t_gnst *gnst);
int		gnst_rev_rotate(t_gnst *gnst);

# define E_SFA "gnst_from_args : gnst_push_back()"
# define E_SFS "gnst_from_str : gnst_push_back()"

#endif