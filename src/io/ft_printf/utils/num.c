/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 18:53:40 by lorenuar          #+#    #+#             */
/*   Updated: 2021/04/04 00:27:37 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	star_return(va_list args, char **f)
{
	ssize_t	val;

	(*f)++;
	val = va_arg(args, int);
	return (val);
}

static ssize_t	sub_ret_read_num(ssize_t num, char sign)
{
	if (num > LONG_MAX)
	{
		if (sign == 1)
			return (-1);
		return (0);
	}
	if (sign == 1)
		return (num);
	return (-num);
}

ssize_t	read_num(va_list args, char **f)
{
	ssize_t	num;
	char	sign;

	num = 0;
	sign = 1;
	while ((f && *f && ((**f >= '\t' && **f <= '\r') || **f == ' ')))
		(*f)++;
	if (f && *f && **f == '-')
		sign = -1;
	while (f && *f && (**f == '-' || **f == '+' || **f == '0' || **f == '*'))
	{
		if (**f == '*')
			return (star_return(args, f));
		(*f)++;
	}
	while (f && *f && **f >= '0' && **f <= '9')
	{
		num = (num * 10) + (**f - '0');
		(*f)++;
	}
	return (sub_ret_read_num(num, sign));
}

ssize_t	sub_put_nbr(ssize_t num, ssize_t base, char *b_chars)
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

size_t	num_len(ssize_t num, ssize_t base)
{
	size_t	len;

	len = 1;
	if (num == 0)
		return (1);
	if (num < 0 && base == 10)
	{
		num = -num;
	}
	while (num > 0)
	{
		len++;
		num /= base;
	}
	len--;
	return (len);
}
