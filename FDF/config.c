/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 20:14:06 by yskrypny          #+#    #+#             */
/*   Updated: 2017/05/07 16:28:40 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_standart_options(t_id *id)
{
	id->cfg->w_w = 1600;
	id->cfg->w_h = 1200;
	id->cfg->px0 = 64;
	id->cfg->py0 = 16;
	id->cfg->diff_x = id->cfg->w_w - 2 * id->cfg->px0;
	id->cfg->diff_y = id->cfg->w_h - 2 * id->cfg->py0;
	id->cfg->dc->c_low = GREEN;
	id->cfg->dc->c_grnd = GREEN;
	id->cfg->dc->c_mid = GREEN;
	id->cfg->dc->c_high = GREEN;
	id->cfg->def_bc = BLACK;
	id->cfg->z_b = 3;
	id->cfg->dgr = 2;
}

void	ft_option_list(t_id *id)
{
	id->cfg->opt_array[0] = "Screen_width   =";
	id->cfg->opt_array[1] = "Screen_heigth  =";
	id->cfg->opt_array[2] = "X-border       =";
	id->cfg->opt_array[3] = "Y-border       =";
	id->cfg->opt_array[4] = "Def_color low  =";
	id->cfg->opt_array[5] = "Def_color grnd =";
	id->cfg->opt_array[6] = "Def_color mid  =";
	id->cfg->opt_array[7] = "Def_color high =";
	id->cfg->opt_array[8] = "BAD_node_color =";
	id->cfg->opt_array[9] = "Rot_degreee    =";
	id->cfg->opt_array[10] = "Intro-file     =";
	id->cfg->opt_array[11] = "Intro-h file   =";
	id->cfg->opt_array[12] = "Help button    =";
	id->cfg->opt_array[13] = "Help screen    =";
}

void	ft_option_array(t_id *id)
{
	int i;

	i = 0;
	id->cfg->opt_array = malloc(sizeof(char *) * (OPT_COUNT + 1));
	id->cfg->opt_array[OPT_COUNT] = NULL;
	while (i < OPT_COUNT)
	{
		id->cfg->opt_array[i] = malloc(sizeof(char) * (16 + 1));
		id->cfg->opt_array[i][16] = '\0';
		i++;
	}
	ft_option_list(id);
}

void	ft_config_init(t_id *id, char *cfg_f)
{
	int fd;

	if ((id->cfg = malloc(sizeof(t_cfg))) == NULL)
		ft_exit_error(555);
	ft_memset(id->cfg, 0, sizeof(t_cfg));
	if ((id->cfg->dc = malloc(sizeof(t_dc))) == NULL)
		ft_exit_error(555);
	ft_memset(id->cfg->dc, 0, sizeof(t_dc));
	ft_standart_options(id);
	if ((fd = open(cfg_f, O_RDONLY)) >= 0)
		ft_parse_options(id, fd);
	else
		write(1, "Config file fail or not found. Using default options.\n", 47);
	close(fd);
}
