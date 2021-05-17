/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 10:48:30 by lorenuar          #+#    #+#             */
/*   Updated: 2021/04/03 21:46:40 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

t_list	*lst_new(void *content)
{
	t_list	*head;

	head = (t_list *)malloc(sizeof(t_list));
	if (!(head))
		return (NULL);
	head->content = content;
	head->next = NULL;
	return (head);
}
