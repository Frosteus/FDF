/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary_search.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 15:46:59 by yskrypny          #+#    #+#             */
/*   Updated: 2016/12/13 15:47:04 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_binary_search(const int *arr, int arr_size, int key_val)
{
	int first;
	int last;
	int search_pos;

	first = 0;
	last = arr_size - 1;
	while (first < last)
	{
		search_pos = first + (last - first) / 2;
		if (key_val <= arr[search_pos])
			last = search_pos;
		else
			first = search_pos + 1;
	}
	if (arr[last] == key_val)
		return (last);
	else
		return (-1);
}
