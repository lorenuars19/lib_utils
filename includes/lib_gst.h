/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_gst.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 18:09:49 by lorenuar          #+#    #+#             */
/*   Updated: 2021/06/24 22:57:47 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_GST_H
# define LIB_GST_H
# include "lib_io.h"
# include <unistd.h>

/*
** gst
*/

# define GST_INIT_SIZ 2
# define GST_SIZ_MULT 2

typedef struct s_generic_nst
{
	void	**dat;
	long	siz;
	long	max_siz;
}			t_gst;

int		gst_new_resize(t_gst *gst);
int		gst_push(t_gst *gst, void *data);
int		gst_push_back(t_gst *gst, void *data);

int		gst_shift_down(t_gst *gst);
int		gst_shift_up(t_gst *gst);

int		gst_pop(t_gst *gst);
int		gst_pop_back(t_gst *gst);

void	gst_free(t_gst *gst);

size_t	gst_get_size(t_gst *gst);

int		gst_swap(t_gst *gst);
int		gst_rotate(t_gst *gst);
int		gst_rev_rotate(t_gst *gst);

#endif
