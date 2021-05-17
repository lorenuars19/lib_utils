/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_list.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 15:05:51 by lorenuar          #+#    #+#             */
/*   Updated: 2021/05/17 22:17:48 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_LIST_H
# define LIB_LIST_H

# include <unistd.h>

/*
** lists
*/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*lst_new(void *content);

void	lst_add_back(t_list **alst, t_list *new);
void	lst_add_front(t_list **alst, t_list *new);
void	lst_free(t_list **lst, void (*del)(void*));
void	lst_delone(t_list *lst, void (*del)(void*));
void	lst_iter(t_list *lst, void (*f)(void *));

size_t	lst_size(t_list *lst);

t_list	*lst_last(t_list *lst);
t_list	*lst_map(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
