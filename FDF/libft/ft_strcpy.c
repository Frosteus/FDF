/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 19:40:24 by yskrypny          #+#    #+#             */
/*   Updated: 2016/12/08 19:40:30 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	char	*p_dest;
	int		i;

	i = 0;
	p_dest = dest;
	while (src[i] != '\0')
	{
		p_dest[i] = src[i];
		i++;
	}
	p_dest[i] = '\0';
	return (dest);
}
