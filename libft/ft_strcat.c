/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 19:39:14 by yskrypny          #+#    #+#             */
/*   Updated: 2016/12/08 19:39:20 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	char *p_dest;

	p_dest = dest;
	while (*p_dest)
		p_dest++;
	while (*src)
	{
		*p_dest = *src;
		p_dest++;
		src++;
	}
	*p_dest = '\0';
	return (dest);
}
