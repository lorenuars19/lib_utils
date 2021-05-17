/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_str.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 15:05:51 by lorenuar          #+#    #+#             */
/*   Updated: 2021/05/17 22:35:30 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_STR_H
# define LIB_STR_H

# include <unistd.h>

/*
** str
*/
size_t	str_len(const char *str);
size_t	str_has(const char *s, char c);
size_t	str_skipto(char **str, char c);

char	*str_jointo(char *s1, char *s2, char **tofree);
char	*str_dupli(const char *to_copy);

int		str_cmp(const char *s1, const char *s2);
int		str_cmp_n(const char *s1, const char *s2, size_t size);
int		is_charset(char c, char *set);

ssize_t	str_to_nbr(const char *s);
ssize_t	str_to_nbr_base(const char *s, int base);

ssize_t	str_eat_nbr(char **f);


#endif
