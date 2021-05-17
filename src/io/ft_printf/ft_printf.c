/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 09:52:05 by lorenuar          #+#    #+#             */
/*   Updated: 2021/04/03 21:54:40 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	call_dispatch(va_list args, t_opt opt)
{
	ssize_t	ret;

	ret = 0;
	if (opt.cv == '%')
		ret += print_char(opt.cv, opt);
	else if (opt.cv == 's')
		ret += print_str(va_arg(args, char *), opt);
	else if (opt.cv == 'c')
		ret += print_char(va_arg(args, int), opt);
	else if (opt.cv == 'd' || opt.cv == 'i')
		ret += print_nbr((ssize_t)va_arg(args, int), BASE_10, opt);
	else if (opt.cv == 'u')
		ret += print_nbr_unsigned((size_t)va_arg(args, int), BASE_10, opt);
	else if (opt.cv == 'x')
		ret += print_nbr_unsigned((size_t)va_arg(args, int), BASE_S_HEX, opt);
	else if (opt.cv == 'X')
		ret += print_nbr_unsigned((size_t)va_arg(args, int), BASE_HEX, opt);
	else if (opt.cv == 'p')
		ret += print_ptr(va_arg(args, void *), opt);
	return (ret);
}

void	sub_get_opts(va_list args, char **fmt, t_opt *opt)
{
	if (**fmt == '-')
		opt->neg = true;
	if (**fmt == '0')
		opt->zr = true;
	if (**fmt == '+')
		opt->pls = true;
	if (**fmt == '#')
		opt->alt = true;
	if (*(*fmt + 1) == '-')
		opt->neg = true;
	opt->fw = read_num(args, fmt);
	if (**fmt == '.')
	{
		(*fmt)++;
		opt->dot = true;
		opt->pr = read_num(args, fmt);
		opt->cv = **fmt;
	}
	else
	{
		opt->cv = **fmt;
	}
	(*fmt)++;
}

ssize_t	get_opt(va_list args, char **fmt)
{
	t_opt	opt;
	ssize_t	ret;

	ret = 0;
	opt = (t_opt){0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	if (!skip_to(fmt, '%'))
		return (ret);
	if (**fmt == ' ')
		opt.spa = true;
	sub_get_opts(args, fmt, &opt);
	if (opt.neg && opt.fw > 0)
		opt.fw = -opt.fw;
	opt.neg = 1;
	if (opt.fw >= 0)
		opt.neg = 0;
	if (opt.cv == 'x' || opt.cv == 'X' || opt.cv == 'p' || opt.cv == 'u')
		opt.uns = true;
	if (opt.pr < 0)
	{
		opt.dot = false;
		opt.pr = 0;
	}
	ret += call_dispatch(args, opt);
	return (ret);
}

int	ft_printf(char *fmt, ...)
{
	ssize_t	ret;
	va_list	args;

	ret = 0;
	va_start(args, fmt);
	while (fmt && *fmt)
	{
		if (*fmt == '%')
		{
			ret += get_opt(args, &fmt);
		}
		if (*fmt != '\0' && *fmt != '%')
		{
			ret += write(1, fmt, 1);
			fmt++;
		}
	}
	va_end(args);
	return ((int)ret);
}
