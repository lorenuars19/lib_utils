/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 18:53:35 by lorenuar          #+#    #+#             */
/*   Updated: 2021/05/22 22:18:58 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

ssize_t	put_char(char c, int fd)
{
	return (write(fd, &c, 1));
}

size_t	sub_put_nbr_uns(size_t num, size_t base, char *b_chars, int fd)
{
	ssize_t	ret;

	ret = 0;
	if (num >= base)
	{
		ret += sub_put_nbr_uns(num / base, base, b_chars, fd);
		ret += sub_put_nbr_uns(num % base, base, b_chars, fd);
	}
	if (num < base)
	{
		put_char(b_chars[num], fd);
		ret += 1;
	}
	return (ret);
}
