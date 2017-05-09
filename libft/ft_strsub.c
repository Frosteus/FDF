/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 19:51:52 by yskrypny          #+#    #+#             */
/*   Updated: 2016/12/08 19:52:01 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *substr;
	char *ptr;

	ptr = NULL;
	if (s != NULL)
	{
		substr = (char *)malloc(sizeof(char) * (len + 1));
		if (substr != NULL)
		{
			ptr = substr;
			while (len > 0)
			{
				*substr = s[start];
				start++;
				substr++;
				len--;
			}
			*substr = '\0';
		}
	}
	return (ptr);
}
