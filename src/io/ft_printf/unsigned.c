/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 19:07:47 by lorenuar          #+#    #+#             */
/*   Updated: 2021/04/04 00:27:09 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	format_ptr_space(t_nstat nst, t_opt opt, int order)
{
	ssize_t	x;

	x = 0;
	if (opt.fw < 0)
		opt.fw = -opt.fw;
	if (opt.fw > nst.len)
	{
		x = opt.fw - nst.len;
	}
	if ((order && !opt.neg) || (!order && opt.neg))
	{
		x = 0;
	}
	return (n_str(" ", x, 1));
}

static void	sub_print_ptr(void *ptr, t_base *bse, t_nstat *nst, int null_len)
{
	*bse = (t_base){16, BASE_S_HEX};
	*nst = (t_nstat){(size_t)ptr,
		num_len_unsigned((size_t)ptr, bse->bse) + null_len, *bse, 0};
}

ssize_t	print_ptr(void *ptr, t_opt opt)
{
	ssize_t	ret;
	t_nstat	nst;
	t_base	bse;
	int		null_len;

	null_len = 2;
	if (opt.dot && opt.pr == 0 && ptr == NULL)
		null_len = 1;
	sub_print_ptr(ptr, &bse, &nst, null_len);
	ret = 0;
	ret += format_ptr_space(nst, opt, 0);
	if (ptr)
	{
		ret += n_str("0x", 1, 0);
		ret += sub_put_nbr_unsigned((size_t)ptr, (size_t)16, BASE_S_HEX);
	}
	else
	{
		if (opt.dot && opt.pr == 0)
			ret += n_str(PTR_DOT_NULL, 1, 0);
		else
			ret += n_str(PTR_NULL, 1, 0);
	}
	ret += format_ptr_space(nst, opt, 1);
	return (ret);
}

ssize_t	print_nbr_unsigned(unsigned int num, char *b_chars, t_opt opt)
{
	ssize_t	ret;
	t_nstat	nst;
	t_base	bse;

	ret = 0;
	if (num > UINT_MAX)
	{
		return (ret);
	}
	bse = (t_base){str_len(b_chars), b_chars};
	nst = (t_nstat){num, num_len(num, bse.bse), bse, 0};
	if (num == 0 && opt.dot && opt.pr == 0)
		nst.len = 0;
	ret += format_nbr_space(opt, nst, 0);
	ret += format_nbr_zero(opt, nst);
	if (!(opt.dot && opt.pr == 0 && num == 0))
	{
		ret += sub_put_nbr_unsigned(num, nst.bse.bse, nst.bse.chr);
	}
	ret += format_nbr_space(opt, nst, 1);
	return (ret);
}

size_t	num_len_unsigned(size_t num, ssize_t base)
{
	size_t	len;

	len = 1;
	if (num == 0)
		return (1);
	if (base == 10)
	{
		num = -num;
	}
	while (num > 0)
	{
		len++;
		num /= base;
	}
	return (len - 1);
}
