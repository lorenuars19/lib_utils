/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:06:44 by lorenuar          #+#    #+#             */
/*   Updated: 2021/05/17 22:34:31 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_io.h"
#include "lib_str.h"

void	put_str(char *str)
{
	write(1, str, str_len(str));
}

void	put_str_nl(char *str)
{
	write(1, str, str_len(str));
	write(1, "\n", 1);
}

void	put_str_fd(int fd, char *str)
{
	write(fd, str, str_len(str));
}

void	put_str_fd_nl(int fd, char *str)
{
	write(fd, str, str_len(str));
	write(fd, "\n", 1);
}
