/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 16:13:03 by yskrypny          #+#    #+#             */
/*   Updated: 2016/12/13 16:13:12 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_sqrt(const float f)
{
	union u_u sqrt;

	sqrt.f = f;
	sqrt.i = (1 << 29) + (sqrt.i >> 1) - (1 << 22);
	sqrt.f = sqrt.f + f / sqrt.f;
	sqrt.f = 0.25f * sqrt.f + f / sqrt.f;
	return (sqrt.f);
}
