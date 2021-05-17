/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 18:53:35 by lorenuar          #+#    #+#             */
/*   Updated: 2021/05/17 22:32:21 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

ssize_t	put_char(char c)
{
	return (write(1, &c, 1));
}

size_t	sub_put_nbr_unsigned(size_t num, size_t base, char *b_chars)
{
	ssize_t	ret;

	ret = 0;
	if (num >= base)
	{
		ret += sub_put_nbr(num / base, base, b_chars);
		ret += sub_put_nbr(num % base, base, b_chars);
	}
	if (num < base)
	{
		put_char(b_chars[num]);
		ret += 1;
	}
	return (ret);
}
