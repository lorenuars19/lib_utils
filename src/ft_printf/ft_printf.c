/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 09:52:05 by lorenuar          #+#    #+#             */
/*   Updated: 2021/05/22 23:09:19 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

ssize_t	get_opt(va_list args, char **fmt, int fd)
{
	t_opt	opt;
	ssize_t	ret;

	ret = 0;
	opt = (t_opt){fd, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
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

int	ft_vprintf(int fd, char *fmt, va_list args)
{
	int		ret;

	ret = 0;
	while (fmt && *fmt && fd > 0)
	{
		if (*fmt == '%')
		{
			ret += get_opt(args, &fmt, fd);
		}
		if (*fmt != '\0' && *fmt != '%')
		{
			ret += write(fd, fmt, 1);
			fmt++;
		}
	}
	return (ret);
}

int	ft_printf_fd(int fd, char *fmt, ...)
{
	int		ret;
	va_list	args;

	va_start(args, fmt);
	ret = ft_vprintf(fd, fmt, args);
	va_end(args);
	return (ret);
}

int	ft_printf(char *fmt, ...)
{
	int		ret;
	va_list	args;

	va_start(args, fmt);
	ret = ft_vprintf(1, fmt, args);
	va_end(args);
	return (ret);
}
