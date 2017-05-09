/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intro_and_help.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 16:56:52 by yskrypny          #+#    #+#             */
/*   Updated: 2017/05/07 16:56:54 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_intro(t_id *id)
{
	t_point p;
	t_d		d;

	id->xpm_f = id->cfg->intro;
	ft_xpm_to_wnd(id, id->xpm_f, 0, 0);
	if (id->xpm_f == NULL)
	{
		p.x = 600;
		p.y = 550;
		d = (t_d){0, 0, 0};
		ft_string_put(id, p, d, "CFG FILE NOT FOUND! PRESS ENTER TO CONTINUE!");
		p.x = 625;
		p.y = 575;
		ft_string_put(id, p, d, "SOME OPTIONS WILL NOT BE AVAILABLE!");
	}
	id->xpm_f = id->cfg->intro_h;
	ft_xpm_to_wnd(id, id->xpm_f, 600, 150);
	id->intro = 0;
}

void	ft_help(t_id *id)
{
	id->xpm_f = id->cfg->c_help;
	ft_xpm_to_wnd(id, id->xpm_f, 0, 50);
}
