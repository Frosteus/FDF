/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 16:51:02 by yskrypny          #+#    #+#             */
/*   Updated: 2017/05/07 16:51:03 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_mlx_param_init(t_id *id)
{
	if ((id->mlx = mlx_init()) == NULL)
		ft_exit_error(555);
	if ((id->wnd = mlx_new_window(id->mlx,
	id->cfg->w_w, id->cfg->w_h, "FDF")) == NULL)
		ft_exit_error(555);
	if ((id->img = malloc(sizeof(t_img))) == NULL)
		ft_exit_error(555);
	ft_memset(id->img, 0, sizeof(t_img));
}

void	ft_transform_vector_init(t_id *id)
{
	if ((id->trv = malloc(sizeof(t_trv))) == NULL)
		ft_exit_error(555);
	ft_memset(id->trv, 0, sizeof(t_trv));
	id->trv->d.dx = id->cfg->diff_x / 2;
	id->trv->d.dy = id->cfg->diff_y / 2;
	id->trv->r = (t_r){0, 0, 0, 0, 0, 0, 0, 0, 0};
	id->trv->r.rx = id->trv->r.rx * DTOR;
	id->trv->r.ry = id->trv->r.ry * DTOR;
	id->trv->r.rz = id->trv->r.rz * DTOR;
	id->trv->s = (t_s){1, 1, 1, 1};
}

void	ft_create_t_function_array(t_id *id)
{
	int i;

	if ((id->trf = malloc(sizeof(t_trv) * FUNC_COUNT)) == NULL)
		ft_exit_error(555);
	ft_memset(id->trf, 0, sizeof(t_fl));
	id->trf[0].func = (void (*)())ft_rotate_x;
	id->trf[1].func = (void (*)())ft_rotate_y;
	id->trf[2].func = (void (*)())ft_rotate_z;
	id->trf[3].func = (void (*)())ft_shift_x;
	id->trf[4].func = (void (*)())ft_shift_y;
	id->trf[5].func = (void (*)())ft_shift_z;
	id->trf[6].func = (void (*)())ft_scale_x;
	id->trf[7].func = (void (*)())ft_scale_y;
	id->trf[8].func = (void (*)())ft_scale_z;
	id->trf[9].func = (void (*)())ft_scale_all;
	i = 0;
	while (i < FUNC_COUNT)
	{
		id->trf[i].flag = 1;
		i++;
	}
}

t_id	*ft_initialize_id_struct(t_id *id, char **av)
{
	if ((id = malloc(sizeof(t_id))) == NULL)
		ft_exit_error(555);
	ft_memset(id, 0, sizeof(t_id));
	ft_config_init(id, "fdf.cfg");
	ft_mlx_param_init(id);
	if ((id->mp = malloc(sizeof(t_mp))) == NULL)
		ft_exit_error(555);
	ft_memset(id->mp, 0, sizeof(t_mp));
	ft_map_read(av[1], id);
	ft_transform_vector_init(id);
	ft_create_t_function_array(id);
	ft_create_and_prep_compass(id);
	id->intro = 1;
	id->cfg->z_b = 1;
	id->a_flag = 0;
	return (id);
}
