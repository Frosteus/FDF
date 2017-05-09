/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 19:50:41 by yskrypny          #+#    #+#             */
/*   Updated: 2016/12/08 19:50:48 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *ptr;

	ptr = (char *)malloc(size + 1);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, (int)'\0', size + 1);
	return (ptr);
}
