/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 19:50:07 by yskrypny          #+#    #+#             */
/*   Updated: 2016/12/08 19:50:15 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	*p_dest;
	size_t	i;

	i = 0;
	p_dest = dest;
	while (i < n && src[i])
	{
		p_dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		p_dest[i] = '\0';
		i++;
	}
	return (dest);
}
