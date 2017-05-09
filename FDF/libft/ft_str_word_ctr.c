/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_word_ctr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 16:59:08 by yskrypny          #+#    #+#             */
/*   Updated: 2016/12/13 16:59:10 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_str_word_ctr(char const *s, char c)
{
	size_t	w_ctr;

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
