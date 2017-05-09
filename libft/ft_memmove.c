/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 19:36:00 by yskrypny          #+#    #+#             */
/*   Updated: 2016/12/08 19:36:06 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *p_dest;
	unsigned char *p_src;

	p_dest = (unsigned char *)dest;
	p_src = (unsigned char *)src;
	if (p_dest == p_src)
		return (dest);
	if (p_dest < p_src)
		ft_memcpy(p_dest, p_src, n);
	else
		while (n > 0)
		{
			p_dest[n - 1] = p_src[n - 1];
			n--;
		}
	return (dest);
}
