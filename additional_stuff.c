/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_stuff.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 16:22:48 by yskrypny          #+#    #+#             */
/*   Updated: 2017/05/07 16:22:53 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_exit_error(int err)
{
	char *err_msg;

	err_msg = "Error ";
	if (err == 114)
		err_msg = "No data for points ";
	else if (err == 113)
		err_msg = "Empty map file ";
	else if (err == 111)
		err_msg = "No such file ";
	perror(err_msg);
	exit(err);
}

void	ft_string_put(t_id *id, t_point point, t_d d, char *str)
{
	point.x += d.dx;
	point.y += d.dy;
	mlx_string_put(id->mlx, id->wnd, (int)point.x, (int)point.y, point.c, str);
}
