/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_nbr.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 15:05:51 by lorenuar          #+#    #+#             */
/*   Updated: 2021/05/17 22:07:30 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_NBR_H
# define LIB_NBR_H

# include <unistd.h>

/*
** nbr
*/
# define BASE_DEFAULT 10
# define BASE_10 "0123456789"
# define BASE_S_HEX "0123456789abcdef"
# define BASE_HEX "0123456789ABCDEF"

ssize_t	put_nbr(ssize_t num);
ssize_t	put_nbr_fd(int fd, ssize_t num);
ssize_t	put_nbr_base(ssize_t num, ssize_t base, char *b_chars);
ssize_t	put_nbr_base_fd(int fd, ssize_t num, ssize_t base, char *b_chars);

size_t	nbr_len(ssize_t num);
size_t	nbr_len_base(ssize_t num, ssize_t base);

char	*nbr_to_str(ssize_t nbr);
char	*nbr_to_str_base(ssize_t nbr, int base, char *b_chars);

#endif
