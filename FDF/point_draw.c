/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 18:13:57 by yskrypny          #+#    #+#             */
/*   Updated: 2017/05/07 18:14:00 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_point_shift_to_img(t_point point, t_d *d, t_img *img)
{
	point.x += d->dx;
	point.y += d->dy;
	point.z += d->dz;
	if (ft_check_vision_img(&point, img) == 1)
		ft_memcpy(img->img_d + (int)(point.y * img->line_s + point.x * img->bs),
		&point.c, (size_t)img->bs);
}

void	ft_point_shift_to_wnd(t_id *id, t_point point, t_d *d)
{
	point.x += d->dx;
	point.y += d->dy;
	point.z += d->dz;
	if (ft_check_vision_wnd(id, &point) == 1)
		mlx_pixel_put(id->mlx, id->wnd, (int)point.x, (int)point.y, point.c);
}

void	ft_point_no_shift_to_img(t_point point, t_img *img)
{
	if (ft_check_vision_img(&point, img) == 1)
		ft_memcpy(img->img_d + (int)(point.y * img->line_s + point.x * img->bs),
		&point.c, (size_t)img->bs);
}

void	ft_point_no_shift_to_wnd(t_id *id, t_point point)
{
	if (ft_check_vision_wnd(id, &point) == 1)
		mlx_pixel_put(id->mlx, id->wnd, (int)point.x, (int)point.y, point.c);
}
