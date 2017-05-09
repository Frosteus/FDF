/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 19:51:03 by yskrypny          #+#    #+#             */
/*   Updated: 2016/12/08 19:51:07 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char *ptr;

	ptr = (char *)str;
	while (*ptr)
	{
		if (c == *ptr)
			str = ptr;
		ptr++;
	}
	if (c == '\0' && *ptr == c)
		return (ptr);
	else if (*str == c)
		return ((char *)str);
	else
		return (NULL);
}
