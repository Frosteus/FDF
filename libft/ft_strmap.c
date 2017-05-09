/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 19:48:17 by yskrypny          #+#    #+#             */
/*   Updated: 2016/12/08 19:48:27 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ptr;
	int		i;

	ptr = NULL;
	if (s != NULL)
	{
		i = 0;
		ptr = ft_strdup(s);
		if (ptr != NULL)
		{
			while (ptr[i])
			{
				ptr[i] = f(ptr[i]);
				i++;
			}
			ptr[i] = '\0';
		}
	}
	return (ptr);
}
