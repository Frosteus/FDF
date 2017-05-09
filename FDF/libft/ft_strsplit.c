/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 16:00:28 by yskrypny          #+#    #+#             */
/*   Updated: 2016/12/10 16:02:25 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_l_ctr(char const *s, char c)
{
	size_t	l_ctr;

	l_ctr = 0;
	while (*s != c && *s)
	{
		l_ctr++;
		s++;
	}
	return (l_ctr);
}

static int		ft_w_ctr(char const *s, char c)
{
	int		w_ctr;

	w_ctr = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			w_ctr++;
			while (*s != c && *s)
				s++;
		}
		else
			s++;
	}
	return (w_ctr);
}

char			**ft_strsplit(char const *s, char c)
{
	int		w_ctr;
	char	**splited;

	if (s == NULL)
		return (NULL);
	w_ctr = ft_w_ctr(s, c);
	splited = (char **)malloc(sizeof(char *) * (w_ctr + 1));
	if (splited != NULL)
	{
		splited[w_ctr] = 0;
		w_ctr = 0;
		while (s != NULL && *s)
		{
			if (*s != c)
			{
				splited[w_ctr] = ft_strnew(ft_l_ctr(s, c));
				splited[w_ctr] = ft_strncpy(splited[w_ctr], s, ft_l_ctr(s, c));
				s = ft_strchr(s, c);
				w_ctr++;
			}
			else
				s++;
		}
	}
	return (splited);
}
