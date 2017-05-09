/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_scale.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 18:35:57 by yskrypny          #+#    #+#             */
/*   Updated: 2017/05/07 18:35:58 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_scale_x(t_id *id, t_point *point)
{
	point->x = point->x * id->trv->s.sx;
}

void	ft_scale_y(t_id *id, t_point *point)
{
	point->y = point->y * id->trv->s.sy;
}

void	ft_scale_z(t_id *id, t_point *point)
{
	point->z = point->z * id->trv->s.sz;
}

void	ft_scale_all(t_id *id, t_point *point)
{
	point->x = point->x * id->trv->s.w;
	point->y = point->y * id->trv->s.w;
	point->z = point->z * id->trv->s.w;
}
