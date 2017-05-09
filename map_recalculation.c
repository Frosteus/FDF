/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_recalculation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 17:04:22 by yskrypny          #+#    #+#             */
/*   Updated: 2017/05/07 17:04:25 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_prepare_map(t_id *id)
{
	int i;
	int j;

	id->step_x = id->cfg->diff_x / id->map_w;
	id->step_y = id->cfg->diff_y / id->map_l;
	id->cen_x = id->map_w / 2 * id->step_x;
	id->cen_y = id->map_l / 2 * id->step_y;
	if (id->mp->mh.z - id->mp->lh.z <= 60)
		id->cfg->z_b = (id->mp->mh.z - id->mp->lh.z <= 25 ? 15 : 10);
	i = 0;
	while (i < id->map_l)
	{
		j = 0;
		while (j < id->map_w)
		{
			id->map[i][j].x = id->map[i][j].x * id->step_x - id->cen_x;
			id->map[i][j].y = id->map[i][j].y * id->step_y - id->cen_y;
			id->map[i][j].z *= id->cfg->z_b;
			j++;
		}
		i++;
	}
}

void	ft_check_changes(t_id *id)
{
	int i;
	int j;

	ft_make_arr_of_transform_functions(id);
	ft_prepare_trv(id);
	i = 0;
	while (i < id->map_l)
	{
		j = 0;
		while (j < id->map_w)
		{
			ft_transform_point(id, &id->map[i][j]);
			j++;
		}
		i++;
	}
	ft_compass_rotation(id);
	ft_clear_trv(id);
}

void	ft_transparency(t_id *id)
{
	int				i;
	int				j;
	unsigned int	c1;

	i = 0;
	c1 = 0xff000000;
	while (i < id->img->h)
	{
		j = 0;
		while (j < id->img->line_s)
		{
			if (*(id->img->img_d + i * id->img->line_s + j) == 0x00
				&& *(id->img->img_d + i * id->img->line_s + j + 1) == 0x00
				&& *(id->img->img_d + i * id->img->line_s + j + 2) == 0x00
				&& *(id->img->img_d + i * id->img->line_s + j + 3) == 0x00)
				ft_memcpy(id->img->img_d + i * id->img->line_s + j, &c1,
				(size_t)id->img->bs);
			j += id->img->bs;
		}
		i++;
	}
}

void	ft_clear_trv(t_id *id)
{
	int i;

	i = 0;
	while (i < FUNC_COUNT)
	{
		id->trf[i].flag = 0;
		i++;
	}
	id->trv->t = (t_t) {0, 0, 0};
	id->trv->r = (t_r) {0, 0, 0, 0, 0, 0, 0, 0, 0};
	id->trv->s = (t_s) {1, 1, 1, 1};
	id->trv->b = (t_b) {0, 0, 0};
}

void	ft_prepare_trv(t_id *id)
{
	id->trv->r.cos_rx = cos(id->trv->r.rx);
	id->trv->r.sin_rx = sin(id->trv->r.rx);
	id->trv->r.cos_ry = cos(id->trv->r.ry);
	id->trv->r.sin_ry = sin(id->trv->r.ry);
	id->trv->r.cos_rz = cos(id->trv->r.rz);
	id->trv->r.sin_rz = sin(id->trv->r.rz);
}
