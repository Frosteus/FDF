/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 15:59:08 by yskrypny          #+#    #+#             */
/*   Updated: 2016/12/10 15:59:23 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*ptr_need;
	char	*ptr_check;
	char	*rem_pos;
	size_t	i;

	ptr_need = (char *)needle;
	ptr_check = (char *)haystack;
	i = ft_strlen(ptr_need);
	if (*ptr_need == '\0')
		return (ptr_check);
	while (*ptr_check && len > 0 && len >= i)
	{
		rem_pos = ptr_check;
		if (ft_strncmp(ptr_check, ptr_need, i) == 0)
			return (rem_pos);
		ptr_check = rem_pos + 1;
		ptr_need = (char *)needle;
		len--;
	}
	return (NULL);
}
