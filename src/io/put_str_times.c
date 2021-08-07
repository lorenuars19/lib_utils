/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_str_times.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 17:26:12 by lorenuar          #+#    #+#             */
/*   Updated: 2021/08/07 16:15:35 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "lib_io.h"
#include "lib_str.h"

ssize_t	put_str_times(char *s, ssize_t n, size_t len)
{
	ssize_t	ret;

	ret = 0;
	while (n && s)
	{
		if (len == 0)
		{
			ret += write(1, s, str_len(s));
		}
		else
		{
			ret += write(1, s, len);
		}
		if (n > 0)
			n--;
		else
			n++;
	}
	return (ret);
}

ssize_t	put_str_times_nl(char *s, ssize_t n, size_t len)
{
	ssize_t	ret;

	ret = 0;
	while (n && s)
	{
		if (len == 0)
		{
			ret += write(1, s, str_len(s));
		}
		else
		{
			ret += write(1, s, len);
		}
		if (n > 0)
			n--;
		else
			n++;
	}
	write(1, "\n", 1);
	return (ret);
}

ssize_t	put_str_times_fd(int fd, char *s, ssize_t n, size_t len)
{
	ssize_t	ret;

	ret = 0;
	while (n && s)
	{
		if (len == 0)
		{
			ret += write(fd, s, str_len(s));
		}
		else
		{
			ret += write(fd, s, len);
		}
		if (n > 0)
			n--;
		else
			n++;
	}
	return (ret);
}

ssize_t	put_str_times_fd_nl(int fd, char *s, ssize_t n, size_t len)
{
	ssize_t	ret;

	ret = 0;
	while (n && s)
	{
		if (len == 0)
		{
			ret += write(fd, s, str_len(s));
		}
		else
		{
			ret += write(fd, s, len);
		}
		if (n > 0)
			n--;
		else
			n++;
	}
	if (write(fd, "\n", 1) == -1)
	{
		return (error_sys_put("write"));
	}
	return (ret);
}
