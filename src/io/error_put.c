/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:10:26 by lorenuar          #+#    #+#             */
/*   Updated: 2021/08/07 16:12:39 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include <stdarg.h>
#include "ft_printf.h"
#include "lib_io.h"
#include "lib_str.h"

/*
** Do not reprint Error if it has already been printed
*/
static int	g_error_already_printed = 0;

static void	error_print(void)
{
	put_str_fd(2, ERR);
	if (!g_error_already_printed)
	{
		g_error_already_printed = 1;
		put_str_fd(2, ERR"Error\n");
	}
}

void	*error_ptr_put(char *s)
{
	error_print();
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
	error_print();
	if (s)
	{
		if (write(2, s, str_len(s)) == -1)
			return (errno);
	}
	put_str_fd(2, RST"\n");
	return (ret);
}

int	error_sys_put(char *msg)
{
	char		*s;

	s = strerror(errno);
	error_print();
	put_str_fd(2, msg);
	put_str_fd(2, " : ");
	put_str_fd(2, s);
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

int	error_printf(int ret, char *fmt, ...)
{
	va_list	args;

	error_print();
	va_start(args, fmt);
	ft_vprintf(2, fmt, args);
	va_end(args);
	put_str_fd(2, RST"\n");
	return (ret);
}
