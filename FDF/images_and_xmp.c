/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_and_xmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 16:49:19 by yskrypny          #+#    #+#             */
/*   Updated: 2017/05/07 16:49:20 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_xpm_to_wnd(t_id *id, char *name, int x, int y)
{
	t_img img;

	if ((img.p_img = mlx_xpm_file_to_image(id->mlx, name, &img.w, &img.h))
		!= NULL)
		ft_put_image(id, &img, x, y);
}

void	ft_create_image(t_id *id, t_img *img, int w, int h)
{
	img->w = w;
	img->h = h;
	if ((img->p_img = mlx_new_image(id->mlx, w, h)) == NULL)
		ft_exit_error(555);
	img->img_d = mlx_get_data_addr(img->p_img, &img->bpp, &img->line_s,
	&img->endian);
	img->bs = img->bpp / 8;
}

void	ft_put_image(t_id *id, t_img *img, int x, int y)
{
	mlx_put_image_to_window(id->mlx, id->wnd, img->p_img, x, y);
	mlx_destroy_image(id->mlx, img->p_img);
}

void	ft_map_to_img_and_wnd(t_id *id)
{
	ft_create_image(id, id->img, id->cfg->diff_x, id->cfg->diff_y);
	id->obj_img = id->img;
	ft_put_map_on_image(id);
	if (id->trpn == 1)
		ft_transparency(id);
	ft_put_image(id, id->img, id->cfg->py0, id->cfg->px0);
}

void	ft_put_map_on_image(t_id *id)
{
	int i;
	int j;

	i = 0;
	while (i < id->map_l)
	{
		j = 0;
		while (j < id->map_w)
		{
			if (i + 1 < id->map_l && id->map[i + 1][j].c != id->cfg->def_bc)
				ft_draw_line_to_img(id, id->map[i][j], id->map[i + 1][j],
									&id->trv->d);
			if (j + 1 < id->map_w && id->map[i][j + 1].c != id->cfg->def_bc)
				ft_draw_line_to_img(id, id->map[i][j], id->map[i][j + 1],
									&id->trv->d);
			j++;
		}
		i++;
	}
}
