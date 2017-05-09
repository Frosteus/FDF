/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 19:35:24 by yskrypny          #+#    #+#             */
/*   Updated: 2016/12/08 19:35:39 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*check1;
	unsigned char	*check2;
	size_t			i;

	i = 0;
	check1 = (unsigned char *)str1;
	check2 = (unsigned char *)str2;
	while (i < n)
	{
		if (check1[i] != check2[i])
			return ((int)check1[i] - (int)check2[i]);
		i++;
	}
	return (0);
}
