/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_draw_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 18:29:13 by yskrypny          #+#    #+#             */
/*   Updated: 2017/05/07 18:29:15 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_prepare_line(t_line *line, t_point *p_st, t_point *p_end, t_d *d)
{
	p_st->x = (int)(p_st->x + d->dx);
	p_st->y = (int)(p_st->y + d->dy);
	p_st->z = (int)(p_st->z + d->dz);
	p_end->x = (int)(p_end->x + d->dx);
	p_end->y = (int)(p_end->y + d->dy);
	p_end->z = (int)(p_end->z + d->dz);
	line->dx = ft_abs((int)(p_end->x - p_st->x));
	line->dy = ft_abs((int)(p_end->y - p_st->y));
	line->sign_x = p_st->x < p_end->x ? 1 : -1;
	line->sign_y = p_st->y < p_end->y ? 1 : -1;
	line->error = line->dx - line->dy;
}

void	ft_draw_line_to_img(t_id *id, t_point p_st, t_point p_end, t_d *d)
{
	t_line line;

	ft_prepare_line(&line, &p_st, &p_end, d);
	if (ft_check_vision_img(&p_end, id->obj_img) == 0
	&& ft_check_vision_img(&p_st, id->obj_img) == 0)
		return ;
	ft_point_no_shift_to_img(p_end, id->obj_img);
	while (p_st.x != p_end.x || p_st.y != p_end.y)
	{
		ft_point_no_shift_to_img(p_st, id->obj_img);
		line.error2 = line.error * 2;
		if (line.error2 > -line.dy)
		{
			line.error -= line.dy;
			p_st.x += line.sign_x;
		}
		if (line.error2 < line.dx)
		{
			line.error += line.dx;
			p_st.y += line.sign_y;
		}
	}
}

void	ft_draw_line_to_wnd(t_id *id, t_point p_st, t_point p_end, t_d *d)
{
	t_line line;

	ft_prepare_line(&line, &p_st, &p_end, d);
	ft_point_no_shift_to_wnd(id, p_end);
	while (p_st.x != p_end.x || p_st.y != p_end.y)
	{
		ft_point_no_shift_to_wnd(id, p_st);
		line.error2 = line.error * 2;
		if (line.error2 > -line.dy)
		{
			line.error -= line.dy;
			p_st.x += line.sign_x;
		}
		if (line.error2 < line.dx)
		{
			line.error += line.dx;
			p_st.y += line.sign_y;
		}
	}
}
