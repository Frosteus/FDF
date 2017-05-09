/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 16:34:04 by yskrypny          #+#    #+#             */
/*   Updated: 2016/12/13 16:34:09 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_quicksort(int *arr, int arr_size)
{
	int start;
	int end;
	int average;

	start = 0;
	end = arr_size - 1;
	average = arr[arr_size / 2];
	while (start <= end)
	{
		while (arr[start] < average)
			start++;
		while (arr[end] > average)
			end--;
		if (start <= end)
		{
			ft_swap(&arr[start], &arr[end], sizeof(int));
			start++;
			end--;
		}
	}
	if (end > 0)
		ft_quicksort(arr, end);
	if (arr_size > start)
		ft_quicksort(arr + start, arr_size - start);
}
