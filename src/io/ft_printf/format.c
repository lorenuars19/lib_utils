/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 10:06:56 by lorenuar          #+#    #+#             */
/*   Updated: 2021/04/04 00:28:09 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_nbr_killswitches(t_opt opt,
			t_nstat nst, int order, ssize_t *x)
{
	ssize_t	r_pr;

	if (!((order && !opt.neg) || (!order && opt.neg))
		&& (!order && opt.neg && opt.dot && opt.pr == 0 && !opt.uns
			&& (opt.fw < nst.len || (opt.pr == 0 && opt.dot))))
		*x = opt.fw - nst.len;
	r_pr = (nst.len);
	if (opt.dot && opt.pr == 0)
		r_pr = 0;
	if ((opt.fw <= nst.len)
		|| (order && !opt.neg) || (!order && opt.neg)
		|| (nst.neg && r_pr > opt.fw)
		|| (order && opt.zr && opt.pr >= opt.fw)
		|| (order && opt.neg && opt.dot && opt.fw < nst.len)
		|| (order && !opt.zr && opt.pr != 0 && opt.fw <= opt.pr)
		|| (!order && (opt.dot || !opt.zr) && opt.fw <= opt.pr)
		|| (!opt.dot && opt.zr && opt.pr <= r_pr && !opt.neg)
		|| (order && opt.uns && opt.neg && opt.dot && opt.fw < nst.len
			&& opt.pr == 0)
		|| (!order && opt.uns && !opt.neg && opt.dot && opt.fw < nst.len
			&& opt.pr == 0))
	{
		*x = 0;
	}
}

static void	sub_format_nbr_spaces(t_opt opt, t_nstat nst, ssize_t r_pr,
																	ssize_t *x)
{
	if (opt.dot && opt.pr == 0 && nst.num != 0 && *x - nst.len >= 0)
	{
		if (*x > 0)
			*x -= nst.len;
		else
			*x += nst.len;
	}
	if (nst.neg && opt.pr != opt.fw && opt.fw != r_pr && *x != 0)
	{
		if (*x < 0)
			(*x)++;
		else
			(*x)--;
	}
}

ssize_t	format_nbr_space(t_opt opt, t_nstat nst, int order)
{
	ssize_t	x;
	ssize_t	r_pr;

	x = 0;
	if (opt.fw < 0)
		opt.fw = -opt.fw;
	r_pr = nst.len;
	if (opt.dot && opt.pr == 0)
		r_pr = 0;
	if (opt.fw >= r_pr)
		x = opt.fw - r_pr;
	if (opt.dot && opt.pr >= r_pr)
		x -= opt.pr - r_pr;
	sub_format_nbr_spaces(opt, nst, r_pr, &x);
	format_nbr_killswitches(opt, nst, order, &x);
	return (n_str(" ", x, 1));
}

ssize_t	format_nbr_zero(t_opt opt, t_nstat nst)
{
	ssize_t	x;

	x = 0;
	if (opt.fw < 0)
		opt.fw = -opt.fw;
	if ((opt.zr || opt.dot))
	{
		x = opt.fw - nst.len;
	}
	if (opt.dot)
		x = opt.pr - nst.len;
	if (nst.neg && !opt.dot)
	{
		if (nst.num > 0)
			x++;
		else
			x--;
	}
	if ((x <= 0 && !opt.dot)
		|| (opt.pr < nst.len && opt.dot) || (opt.zr && opt.neg && !opt.dot))
	{
		x = 0;
	}
	return (n_str(&nst.bse.chr[0], x, 1));
}

ssize_t	print_nbr(ssize_t num, char *b_chars, t_opt opt)
{
	ssize_t	ret;
	t_nstat	nst;
	t_base	bse;

	ret = 0;
	if (num < INT_MIN || num > INT_MAX)
		return (ret);
	bse = (t_base){str_len(b_chars), b_chars};
	nst = (t_nstat){num, num_len(num, bse.bse), bse, 0};
	if (num < 0)
		nst.neg = 1;
	if (num == 0 && opt.dot && opt.pr == 0)
		nst.len = 0;
	ret += format_nbr_space(opt, nst, 0);
	if (num < 0)
		ret += put_char('-');
	ret += format_nbr_zero(opt, nst);
	if (!(opt.dot && opt.pr == 0 && num == 0))
	{
		if (num < 0)
			num = -num;
		ret += sub_put_nbr(num, nst.bse.bse, nst.bse.chr);
	}
	ret += format_nbr_space(opt, nst, 1);
	return (ret);
}
