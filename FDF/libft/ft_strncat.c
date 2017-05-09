/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 19:49:04 by yskrypny          #+#    #+#             */
/*   Updated: 2016/12/08 19:49:13 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char	*p_dest;
	size_t	i;

	i = 0;
	p_dest = dest;
	while (*p_dest != '\0')
		p_dest++;
	while (src[i] != '\0' && i < n)
	{
		p_dest[i] = src[i];
		i++;
	}
	p_dest[i] = '\0';
	return (dest);
}
