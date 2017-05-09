/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 19:48:35 by yskrypny          #+#    #+#             */
/*   Updated: 2016/12/08 19:48:46 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ptr;
	unsigned int	i;

	ptr = NULL;
	if (s != NULL)
	{
		i = 0;
		ptr = ft_strdup(s);
		if (ptr != NULL)
		{
			while (ptr[i])
			{
				ptr[i] = f(i, ptr[i]);
				i++;
			}
			ptr[i] = '\0';
		}
	}
	return (ptr);
}
