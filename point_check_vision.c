/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_check_vision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 17:16:16 by yskrypny          #+#    #+#             */
/*   Updated: 2017/05/07 17:16:17 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_check_vision_img(t_point *point, t_img *img)
{
	if (point->x > 0 && point->y > 0
		&& point->x < img->w && point->y < img->h)
		return (1);
	return (0);
}

int		ft_check_vision_wnd(t_id *id, t_point *point)
{
	if (point->x > 0 && point->y > 0
		&& point->x < id->cfg->w_w && point->y < id->cfg->w_h)
		return (1);
	return (0);
}
