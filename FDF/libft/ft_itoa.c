/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 19:31:08 by yskrypny          #+#    #+#             */
/*   Updated: 2016/12/08 19:31:40 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_len(int n)
{
	int len;

	len = 0;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	len++;
	return (len);
}

char		*ft_itoa(int n)
{
	char	*nbr;
	char	*p_nbr;
	int		num;

	nbr = (char *)malloc(sizeof(char) * (ft_num_len(n) + 1));
	if (nbr != NULL)
	{
		p_nbr = nbr;
		if (n == 0)
			*p_nbr++ = 0 + '0';
		else
		{
			while (n != 0)
			{
				num = n;
				n /= 10;
				*p_nbr++ = "9876543210123456789"[9 + num - n * 10];
			}
			if (num < 0)
				*p_nbr++ = '-';
		}
		*p_nbr++ = '\0';
	}
	return (ft_strrev(nbr));
}
