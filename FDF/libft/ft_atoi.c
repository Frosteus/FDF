/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 19:27:27 by yskrypny          #+#    #+#             */
/*   Updated: 2016/12/08 19:27:43 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				n;
	unsigned char	*ptr;
	char			sign;

	n = 0;
	sign = 0;
	if (str == NULL)
		return (0);
	ptr = (unsigned char *)str;
	while (*ptr == ' ' || *ptr == '\n' || *ptr == '\t' || *ptr == '\v'
	|| *ptr == '\f' || *ptr == '\r')
		ptr++;
	if (*ptr == '+' || *ptr == '-')
	{
		sign = *ptr;
		ptr++;
	}
	while (ft_isdigit(*ptr))
	{
		n = n * 10 + (*ptr - '0');
		ptr++;
	}
	return ((sign == '-') ? -n : n);
}
