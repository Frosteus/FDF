/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compass.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 16:20:04 by yskrypny          #+#    #+#             */
/*   Updated: 2017/05/07 16:20:09 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_create_and_prep_compass(t_id *id)
{
	if ((id->com = malloc(sizeof(t_compass))) == NULL)
		ft_exit_error(555);
	ft_memset(id->com, 0, sizeof(t_compass));
	id->com->d.dx = 150;
	id->com->d.dy = 150;
	id->com->d.dz = 0;
	id->com->c.c = YELLOW;
	id->com->x.x = 64;
	id->com->x.c = RED;
	id->com->y.y = 64;
	id->com->y.c = GREEN;
	id->com->z.z = 64;
	id->com->z.c = BLUE;
}

void	ft_compass_rotation(t_id *id)
{
	ft_rotate_x(id, &id->com->x);
	ft_rotate_x(id, &id->com->y);
	ft_rotate_x(id, &id->com->z);
	ft_rotate_y(id, &id->com->x);
	ft_rotate_y(id, &id->com->y);
	ft_rotate_y(id, &id->com->z);
	ft_rotate_z(id, &id->com->x);
	ft_rotate_z(id, &id->com->y);
	ft_rotate_z(id, &id->com->z);
}

void	ft_draw_compass(t_id *id)
{
	ft_draw_line_to_wnd(id, id->com->x, id->com->c, &id->com->d);
	ft_draw_line_to_wnd(id, id->com->y, id->com->c, &id->com->d);
	ft_draw_line_to_wnd(id, id->com->z, id->com->c, &id->com->d);
	ft_string_put(id, id->com->x, id->com->d, "X");
	ft_string_put(id, id->com->y, id->com->d, "Y");
	ft_string_put(id, id->com->z, id->com->d, "Z");
}
