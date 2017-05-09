/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 16:59:48 by yskrypny          #+#    #+#             */
/*   Updated: 2017/05/07 16:59:49 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_draw(t_id *id)
{
	ft_check_changes(id);
	ft_map_to_img_and_wnd(id);
	ft_xpm_to_wnd(id, id->cfg->h_btn, 0, 0);
	ft_draw_compass(id);
	id->status = 0;
	return (0);
}

void	ft_animation(t_id *id)
{
	id->trv->r.rz = id->cfg->dgr / 2 * DTOR;
	id->trf[F_RZ].flag = 1;
	ft_draw(id);
}

int		ft_redraw(t_id *id)
{
	if (id->intro == 1)
		ft_intro(id);
	if (id->status == 1 && id->start == 1)
		ft_draw(id);
	if (id->a_flag == 1)
		ft_animation(id);
	if (id->s_hlp == 1)
		ft_help(id);
	return (0);
}

int		main(int ac, char **av)
{
	t_id *id;

	if (ac == 1)
	{
		write(1, "usage: ./fdf <map-file name>\n You can change different", 54);
		write(1, " options by using fdf.cfg file.\n", 32);
	}
	else if (ac == 2)
	{
		id = NULL;
		id = ft_initialize_id_struct(id, av);
		ft_prepare_map(id);
		mlx_hook(id->wnd, 2, 5, ft_my_key_function, id);
		mlx_mouse_hook(id->wnd, ft_my_mouse_function, id);
		mlx_loop_hook(id->mlx, ft_redraw, id);
		mlx_loop(id->mlx);
	}
	else if (ac > 2)
		write(1, "Using too much arguments.\n", 26);
	return (0);
}
