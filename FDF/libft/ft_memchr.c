/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 19:35:05 by yskrypny          #+#    #+#             */
/*   Updated: 2016/12/08 19:35:13 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char *ptr;

	ptr = (unsigned char *)str;
	while (n > 0)
	{
		if ((unsigned char)c == *ptr)
			return (ptr);
		ptr++;
		n--;
	}
	return (NULL);
}
