/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 16:24:25 by yskrypny          #+#    #+#             */
/*   Updated: 2017/05/07 16:24:27 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_parse_cfgf_int(int *prm, char *opt, char *str, int fd)
{
	size_t	len;

	len = ft_strlen(opt);
	ft_get_line(fd, &str);
	if (ft_strncmp(opt, str, len) == 0)
		*prm = ft_atoi(ft_strsub(str, (int)(len), ft_strlen(str) - len));
	free(str);
}

void	ft_parse_cfgf_double(double *prm, char *opt, char *str, int fd)
{
	size_t	len;

	len = ft_strlen(opt);
	ft_get_line(fd, &str);
	if (ft_strncmp(opt, str, len) == 0)
		*prm = ft_atoi(ft_strsub(str, (int)(len), ft_strlen(str) - len));
	free(str);
}

void	ft_parse_cfgf_uint(unsigned int *prm, char *opt, char *str, int fd)
{
	size_t	len;

	len = ft_strlen(opt);
	ft_get_line(fd, &str);
	if (ft_strncmp(opt, str, len) == 0)
		*prm = (unsigned int)ft_strtol(ft_strsub(str, (int)(len),
		ft_strlen(str) - len), NULL, 16);
	free(str);
}

void	ft_parse_cfgf_str(char **prm, char *opt, char *str, int fd)
{
	size_t	len;

	len = ft_strlen(opt);
	ft_get_line(fd, &str);
	if (ft_strncmp(opt, str, len) == 0)
		*prm = ft_strsub(str, (int)(len), ft_strlen(str) - len);
	free(str);
}

void	ft_parse_options(t_id *id, int fd)
{
	char	*str;

	str = ft_strnew(0);
	ft_option_array(id);
	ft_parse_cfgf_int(&id->cfg->w_w, id->cfg->opt_array[0], str, fd);
	ft_parse_cfgf_int(&id->cfg->w_h, id->cfg->opt_array[1], str, fd);
	ft_parse_cfgf_int(&id->cfg->px0, id->cfg->opt_array[2], str, fd);
	ft_parse_cfgf_int(&id->cfg->py0, id->cfg->opt_array[3], str, fd);
	id->cfg->diff_x = id->cfg->w_w - 2 * id->cfg->py0;
	id->cfg->diff_y = id->cfg->w_h - 2 * id->cfg->px0;
	ft_parse_cfgf_uint(&id->cfg->dc->c_low, id->cfg->opt_array[4], str, fd);
	ft_parse_cfgf_uint(&id->cfg->dc->c_grnd, id->cfg->opt_array[5], str, fd);
	ft_parse_cfgf_uint(&id->cfg->dc->c_mid, id->cfg->opt_array[6], str, fd);
	ft_parse_cfgf_uint(&id->cfg->dc->c_high, id->cfg->opt_array[7], str, fd);
	ft_parse_cfgf_uint(&id->cfg->def_bc, id->cfg->opt_array[8], str, fd);
	ft_parse_cfgf_double(&id->cfg->dgr, id->cfg->opt_array[9], str, fd);
	ft_parse_cfgf_str(&id->cfg->intro, id->cfg->opt_array[10], str, fd);
	ft_parse_cfgf_str(&id->cfg->intro_h, id->cfg->opt_array[11], str, fd);
	ft_parse_cfgf_str(&id->cfg->h_btn, id->cfg->opt_array[12], str, fd);
	ft_parse_cfgf_str(&id->cfg->c_help, id->cfg->opt_array[13], str, fd);
}
