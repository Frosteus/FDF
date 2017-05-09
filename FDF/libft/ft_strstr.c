/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 19:51:37 by yskrypny          #+#    #+#             */
/*   Updated: 2016/12/08 19:51:46 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char *ptr_need;
	char *ptr_check;
	char *rem_pos;

	ptr_need = (char *)needle;
	ptr_check = (char *)haystack;
	if (*ptr_need == '\0')
		return (ptr_check);
	while (*ptr_check)
	{
		rem_pos = ptr_check;
		while (*ptr_need == *ptr_check && *ptr_need != '\0')
		{
			ptr_check++;
			ptr_need++;
		}
		if (*ptr_need == '\0')
			return (rem_pos);
		ptr_check = rem_pos + 1;
		ptr_need = (char *)needle;
	}
	return (NULL);
}
