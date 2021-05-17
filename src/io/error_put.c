/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:10:26 by lorenuar          #+#    #+#             */
/*   Updated: 2021/04/04 00:39:49 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

/*
** Do not reprint Error if it has already been printed
*/

static int	g_error_already_printed = 0;

void	*error_ptr_put(char *s)
{
	put_str_fd(2, ERR);
	if (!g_error_already_printed)
	{
		g_error_already_printed = 1;
		put_str_fd(2, ERR"Error\n");
	}
	if (s)
	{
		if (write(2, s, str_len(s)) == -1)
			return (NULL);
	}
	put_str_fd(2, RST"\n");
	return (NULL);
}

int	error_put(int ret, char *s)
{
	put_str_fd(2, ERR);
	if (!g_error_already_printed)
	{
		g_error_already_printed = 1;
		put_str_fd(2, ERR"Error\n");
	}
	if (s)
	{
		if (write(2, s, str_len(s)) == -1)
			return (errno);
	}
	put_str_fd(2, RST"\n");
	return (ret);
}

int	error_sys_put(int err)
{
	char		*s;

	s = strerror(err);
	put_str_fd(2, ERR);
	if (!g_error_already_printed)
	{
		g_error_already_printed = 1;
		put_str_fd(2, "Error\n");
	}
	put_str_fd(2, "System : ");
	if (s)
	{
		if (write(2, s, str_len(s)) == -1)
		{
			return (errno);
		}
	}
	put_str_fd(2, RST"\n");
	return (err);
}
