/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 19:39:35 by yskrypny          #+#    #+#             */
/*   Updated: 2016/12/08 19:39:41 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char *ptr;

	ptr = (char *)str;
	while (*ptr)
	{
		if ((unsigned char)c == *ptr)
			return (ptr);
		ptr++;
	}
	if (*ptr == (unsigned char)c)
		return (ptr);
	else
		return (NULL);
}
