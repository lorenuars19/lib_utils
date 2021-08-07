/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_nst.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 15:05:51 by lorenuar          #+#    #+#             */
/*   Updated: 2021/06/22 17:36:08 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_NST_H
# define LIB_NST_H
# include <unistd.h>

/*
** nst
*/

# define NST_INIT_SIZ 2
# define NST_SIZ_MULT 1.5

typedef struct s_number_stack
{
	long	*dat;
	long	siz;
	long	max_siz;
}			t_nst;

int		nst_new_resize(t_nst *nst);
int		nst_push(t_nst *nst, long data);
int		nst_push_back(t_nst *nst, long data);

int		nst_shift_down(t_nst *nst);
int		nst_shift_up(t_nst *nst);

int		nst_pop(t_nst *nst);
int		nst_pop_back(t_nst *nst);

void	nst_free(t_nst *nst);

size_t	nst_get_size(t_nst *nst);

int		nst_from_args(int argc, char *argv[], t_nst *a, int offs);
int		nst_from_str(char *str, t_nst *a);

int		nst_swap(t_nst *nst);
int		nst_rotate(t_nst *nst);
int		nst_rev_rotate(t_nst *nst);

# define E_SFA "nst_from_args : nst_push_back()"
# define E_SFS "nst_from_str : nst_push_back()"

#endif
