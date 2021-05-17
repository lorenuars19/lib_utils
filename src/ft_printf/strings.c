/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 10:06:50 by lorenuar          #+#    #+#             */
/*   Updated: 2021/04/03 23:55:27 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	n_str(char *s, ssize_t n, size_t len)
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

size_t	skip_to(char **fmt, char c)
{
	size_t	skipped;

	skipped = 1;
	while (fmt && *fmt && **fmt)
	{
		if (c == **fmt)
		{
			*fmt = *fmt + 1;
			return (skipped);
		}
		*fmt = *fmt + 1;
		skipped++;
	}
	return (0);
}

ssize_t	format_str_spaces(ssize_t slen, t_opt opt, int order)
{
	ssize_t	x;

	x = 0;
	if (opt.fw < 0)
		opt.fw = -opt.fw;
	if (!order && !opt.neg && opt.pr < slen
		&& opt.pr < opt.fw && slen < opt.fw)
	{
		x = opt.fw - opt.pr;
	}
	if ((!opt.dot && opt.fw >= slen) || (opt.dot))
	{
		x = opt.fw - slen;
	}
	if (opt.pr == 0 && opt.dot)
	{
		x = opt.fw;
	}
	if (x < 0 || (!opt.neg && order) || (!order && opt.neg))
	{
		x = 0;
	}
	return (n_str(" ", x, 1));
}

ssize_t	print_str(char *s, t_opt opt)
{
	ssize_t	ret;
	ssize_t	slen;

	ret = 0;
	if (s == NULL)
	{
		return (print_str("(null)", opt));
	}
	slen = str_len(s);
	if (opt.pr <= slen && opt.pr >= 0 && opt.dot)
		slen = opt.pr;
	ret += format_str_spaces(slen, opt, 0);
	if (!(opt.pr == 0 && opt.dot))
	{
		ret += n_str(s, 1, slen);
	}
	ret += format_str_spaces(slen, opt, 1);
	return (ret);
}

ssize_t	print_char(char c, t_opt opt)
{
	ssize_t	ret;

	ret = 0;
	if (c == '%' && opt.zr && (opt.fw > 0 || (opt.dot && opt.fw > 0)))
	{
		ret += n_str("0", opt.fw - 1, 1);
	}
	if (opt.fw > 0 && !(c == '%' && opt.zr))
		ret += n_str(" ", opt.fw - 1, 1);
	ret += n_str(&c, 1, 1);
	if (opt.fw < 0)
		ret += n_str(" ", opt.fw + 1, 1);
	return (ret);
}
