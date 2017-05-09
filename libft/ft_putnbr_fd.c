/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 19:37:59 by yskrypny          #+#    #+#             */
/*   Updated: 2016/12/08 19:38:06 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int num;

	if (fd >= 0)
	{
		num = (unsigned int)(n >= 0 ? n : -n);
		if (n < 0)
			ft_putchar_fd('-', fd);
		if (num >= 10)
		{
			ft_putnbr_fd(num / 10, fd);
			ft_putchar_fd((char)(num % 10 + '0'), fd);
		}
		else
			ft_putchar_fd((char)(num + '0'), fd);
	}
}
