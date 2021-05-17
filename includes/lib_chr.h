/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_chr.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 15:05:51 by lorenuar          #+#    #+#             */
/*   Updated: 2021/05/17 23:08:14 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_CHR_H
# define LIB_CHR_H

/*
** chr
*/
int		is_charset(char c, char *set);

int		is_alnum(int c);
int		is_alnum_sign(int c);

int		is_alpha(int c);
int		is_alpha_upper(int c);
int		is_alpha_lower(int c);

int		is_digit(int c);
int		is_digit_sign(int c);

int		is_ascii(int c);
int		is_print(int c);

int		is_wsp(char c);
int		is_wsp_nl(char c);

#endif
