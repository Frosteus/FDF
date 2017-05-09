/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 19:38:26 by yskrypny          #+#    #+#             */
/*   Updated: 2016/12/08 19:38:29 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int num;

	num = (unsigned int)(n >= 0 ? n : -n);
	if (n < 0)
		ft_putchar('-');
	if (num >= 10)
	{
		ft_putnbr(num / 10);
		ft_putchar((char)(num % 10 + '0'));
	}
	else
		ft_putchar((char)(num + '0'));
}
