/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 16:46:24 by yskrypny          #+#    #+#             */
/*   Updated: 2017/04/17 16:46:45 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_count_nums(unsigned int n, int base)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= base;
		i++;
	}
	return (i);
}

char		*ft_itoa_base(int value, int base)
{
	unsigned int	n;
	int				sign;
	char			*str;
	int				len;

	sign = 0;
	if (base < 2 || base > 16)
		return (NULL);
	if (base == 10 && value < 0)
		sign = 1;
	n = (value < 0 ? (unsigned int)-value : (unsigned int)value);
	len = ft_count_nums(n, base) + sign;
	if ((str = malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		str[len - 1] = "0123456789ABCDEF"[n % base];
		n /= base;
		len--;
	}
	if (sign == 1)
		str[len] = '-';
	return (str);
}
