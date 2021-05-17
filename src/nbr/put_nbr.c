/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 17:25:44 by lorenuar          #+#    #+#             */
/*   Updated: 2021/05/17 22:20:47 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_nbr.h"
#include "lib_io.h"

ssize_t	put_nbr(ssize_t num)
{
	ssize_t	ret;

	ret = 0;
	if (num >= BASE_DEFAULT)
	{
		ret += put_nbr(num / BASE_DEFAULT);
		ret += put_nbr(num % BASE_DEFAULT);
	}
	if (num < BASE_DEFAULT)
	{
		put_chr('0' + num);
		ret += 1;
	}
	return (ret);
}

ssize_t	put_nbr_base(ssize_t num, ssize_t base, char *b_chars)
{
	ssize_t	ret;

	ret = 0;
	if (num >= base)
	{
		ret += put_nbr_base(num / base, base, b_chars);
		ret += put_nbr_base(num % base, base, b_chars);
	}
	if (num < base)
	{
		put_chr(b_chars[num]);
		ret += 1;
	}
	return (ret);
}
