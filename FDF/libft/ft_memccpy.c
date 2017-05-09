/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 19:34:47 by yskrypny          #+#    #+#             */
/*   Updated: 2016/12/08 19:34:54 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char *p_dest;
	unsigned char *p_src;

	p_dest = (unsigned char *)dest;
	p_src = (unsigned char *)src;
	while (n > 0)
	{
		*p_dest = *p_src;
		if (*p_src == (unsigned char)c)
			return (p_dest + 1);
		p_dest++;
		p_src++;
		n--;
	}
	return (NULL);
}
