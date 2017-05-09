/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 19:46:31 by yskrypny          #+#    #+#             */
/*   Updated: 2016/12/08 19:46:39 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t i;
	size_t n;
	size_t dst_len;
	size_t src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dst_len < siz)
	{
		i = dst_len;
		n = siz - dst_len - 1;
		while (n > 0)
		{
			dst[i] = *src;
			i++;
			src++;
			n--;
		}
		dst[i] = '\0';
		return (dst_len + src_len);
	}
	else
		return (siz + src_len);
}
