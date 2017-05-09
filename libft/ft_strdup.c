/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 19:41:05 by yskrypny          #+#    #+#             */
/*   Updated: 2016/12/08 19:41:14 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*dup_str;
	size_t	len;

	len = ft_strlen(str) + 1;
	dup_str = (char *)malloc(sizeof(char) * (len));
	if (dup_str == NULL)
		return (NULL);
	return (ft_memcpy(dup_str, str, len));
}
