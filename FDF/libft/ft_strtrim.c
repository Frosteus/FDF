/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 22:15:45 by yskrypny          #+#    #+#             */
/*   Updated: 2016/12/08 22:15:55 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*ptr;
	size_t	len;

	if (s != NULL)
	{
		while (*s == ' ' || *s == '\n' || *s == '\t')
			s++;
		len = ft_strlen(s);
		while (len && (s[len - 1] == ' ' || s[len - 1] == '\n'
		|| s[len - 1] == '\t'))
			len--;
		ptr = (char *)malloc(sizeof(char) * (len + 1));
		if (ptr != NULL)
		{
			ft_memcpy(ptr, s, len);
			ptr[len] = '\0';
			return (ptr);
		}
	}
	return (NULL);
}
