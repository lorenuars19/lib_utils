/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_dispatch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 09:52:05 by lorenuar          #+#    #+#             */
/*   Updated: 2021/05/22 23:07:24 by lorenuar         ###   ########.fr       */
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
