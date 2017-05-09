/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_shift.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 18:36:35 by yskrypny          #+#    #+#             */
/*   Updated: 2017/05/07 18:36:37 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_shift_x(t_id *id, t_point *point)
{
	point->x += id->trv->t.tx;
}

void	ft_shift_y(t_id *id, t_point *point)
{
	point->y += id->trv->t.ty;
}

void	ft_shift_z(t_id *id, t_point *point)
{
	point->z += id->trv->t.tz;
}
