/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 16:55:39 by yskrypny          #+#    #+#             */
/*   Updated: 2017/05/07 16:55:46 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_my_key_function(int keycode, t_id *id)
{
	ft_general_keys(keycode, id);
	if (id->start == 1 && id->s_hlp == 0)
	{
		ft_shift_keys(keycode, id);
		ft_rotation_xy_keys(keycode, id);
		ft_rotation_z_scale_keys(keycode, id);
		ft_transparency_animation_keys(keycode, id);
		id->status = 1;
	}
	if (keycode == K_ESC)
		exit(0);
	return (0);
}

void	ft_mouse_button_click(int button, int x, int y, t_id *id)
{
	if (id->start == 1 && x > 0 && x < 200 && y > 0 && y < 50
	&& button == M_BTN_L)
	{
		if (id->s_hlp == 1)
		{
			mlx_clear_window(id->mlx, id->wnd);
			id->s_hlp = 0;
		}
		else
		{
			id->a_flag = 0;
			id->s_hlp = 1;
		}
	}
}

int		ft_my_mouse_function(int button, int x, int y, t_id *id)
{
	ft_mouse_button_click(button, x, y, id);
	if (id->start == 1 && id->s_hlp == 0)
	{
		if (button == M_WHL_D || button == M_BTN_R)
		{
			id->trv->s.w = 0.9;
			id->trf[F_SW].flag = 1;
		}
		if (button == M_WHL_U)
		{
			id->trv->s.w = 1.1;
			id->trf[F_SW].flag = 1;
		}
		id->status = 1;
	}
	return (0);
}
