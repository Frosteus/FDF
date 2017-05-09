/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 18:12:44 by yskrypny          #+#    #+#             */
/*   Updated: 2017/03/16 18:12:46 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap(void *a, void *b, size_t size)
{
	void *tmp;

	tmp = (void *)malloc(sizeof(char) * size);
	memcpy(tmp, b, size);
	memcpy(b, a, size);
	memcpy(a, tmp, size);
	free(tmp);
}
