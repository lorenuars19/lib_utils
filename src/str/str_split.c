/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 18:22:05 by lorenuar          #+#    #+#             */
/*   Updated: 2021/08/04 17:59:10 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lib_str.h"

static int	lento_set(char const *s, char *set)
{
	int		i;

	i = 0;
	while (s && s[i] && !is_charset(s[i], set))
		i++;
	return (i);
}

static int	count_words(char const *s, char *set)
{
	int	count;
	int	pos;

	count = 0;
	pos = 0;
	while (s && s[pos])
	{
		if (is_charset(s[pos], set))
		{
			count++;
		}
		pos++;
	}
	return (count + 1);
}

static char	*tmp_str(const char *s, char *set)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = malloc(sizeof(char) * (lento_set(s, set) + 1));
	if (!tmp)
		return (NULL);
	while (s[i] && !is_charset(s[i], set) && s[i])
	{
		tmp[i] = s[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

int	sub_str_split(char *s, char *set, char **split, int words)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (s && s[i] && y < words)
	{
		if (s && !is_charset(s[i], set))
		{
			split[y] = tmp_str(&s[i], set);
			if (!split[y])
			{
				while (--y >= 0)
					free(split[y]);
				free(split);
				return (1);
			}
			i = i + lento_set(&s[i], set);
			y++;
		}
		else if (is_charset(s[i], set))
			i++;
	}
	split[y] = NULL;
	return (0);
}

char	**str_split(char *s, char *set)
{
	char	**split;
	int		words;

	if (!s || !set)
		return (NULL);
	words = count_words(s, set);
	split = malloc(sizeof(char *) * (words + 1));
	if (!split)
		return (NULL);
	if (sub_str_split(s, set, split, words))
		return (NULL);
	return (split);
}
