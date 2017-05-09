/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_keycode_functions.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 16:29:23 by yskrypny          #+#    #+#             */
/*   Updated: 2017/05/07 16:29:25 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_general_keys(int keycode, t_id *id)
{
	if (id->start == 0)
	{
		if (keycode == K_ENTER)
		{
			mlx_clear_window(id->mlx, id->wnd);
			id->start = 1;
			id->status = 1;
		}
	}
	if (id->start == 1 && keycode == K_FN_1)
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

void	ft_shift_keys(int keycode, t_id *id)
{
	if (keycode == K_LEFT)
	{
		id->trv->t.tx -= 20;
		id->trf[F_TX].flag = 1;
	}
	if (keycode == K_RIGHT)
	{
		id->trv->t.tx += 20;
		id->trf[F_TX].flag = 1;
	}
	if (keycode == K_UP)
	{
		id->trv->t.ty -= 20;
		id->trf[F_TY].flag = 1;
	}
	if (keycode == K_DOWN)
	{
		id->trv->t.ty += 20;
		id->trf[F_TY].flag = 1;
	}
}

void	ft_rotation_xy_keys(int keycode, t_id *id)
{
	if (keycode == K_W)
	{
		id->trv->r.rx = id->cfg->dgr * DTOR;
		id->trf[F_RX].flag = 1;
	}
	if (keycode == K_S)
	{
		id->trv->r.rx = -id->cfg->dgr * DTOR;
		id->trf[F_RX].flag = 1;
	}
	if (keycode == K_Q)
	{
		id->trv->r.ry = -id->cfg->dgr * DTOR;
		id->trf[F_RY].flag = 1;
	}
	if (keycode == K_E)
	{
		id->trv->r.ry = id->cfg->dgr * DTOR;
		id->trf[F_RY].flag = 1;
	}
}

void	ft_rotation_z_scale_keys(int keycode, t_id *id)
{
	if (keycode == K_A)
	{
		id->trv->r.rz = -id->cfg->dgr * DTOR;
		id->trf[F_RZ].flag = 1;
	}
	if (keycode == K_D)
	{
		id->trv->r.rz = id->cfg->dgr * DTOR;
		id->trf[F_RZ].flag = 1;
	}
	if (keycode == K_SUB)
	{
		id->trv->s.w = 0.9;
		id->trf[F_SW].flag = 1;
	}
	if (keycode == K_ADD)
	{
		id->trv->s.w = 1.1;
		id->trf[F_SW].flag = 1;
	}
}

void	ft_transparency_animation_keys(int keycode, t_id *id)
{
	if (keycode == K_T)
	{
		if (id->trpn == 1)
			id->trpn = 0;
		else
			id->trpn = 1;
	}
	if (keycode == K_R)
		id->a_flag = (id->a_flag == 1 ? 0 : 1);
}
