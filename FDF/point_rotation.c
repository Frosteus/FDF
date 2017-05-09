/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_rotation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 18:34:54 by yskrypny          #+#    #+#             */
/*   Updated: 2017/05/07 18:34:56 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_rotate_x(t_id *id, t_point *point)
{
	double temp_c;

	temp_c = point->y;
	point->y = point->y * id->trv->r.cos_rx - point->z * id->trv->r.sin_rx;
	point->z = temp_c * id->trv->r.sin_rx + point->z * id->trv->r.cos_rx;
}

void	ft_rotate_y(t_id *id, t_point *point)
{
	double temp_c;

	temp_c = point->x;
	point->x = point->x * id->trv->r.cos_ry + point->z * id->trv->r.sin_ry;
	point->z = temp_c * -id->trv->r.sin_ry + point->z * id->trv->r.cos_ry;
}

void	ft_rotate_z(t_id *id, t_point *point)
{
	double temp_c;

	temp_c = point->x;
	point->x = point->x * id->trv->r.cos_rz - point->y * id->trv->r.sin_rz;
	point->y = temp_c * id->trv->r.sin_rz + point->y * id->trv->r.cos_rz;
}
