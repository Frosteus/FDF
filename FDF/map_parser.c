/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 17:02:52 by yskrypny          #+#    #+#             */
/*   Updated: 2017/05/07 17:02:53 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_node_check(t_point *map_ptr, char *map_zc)
{
	char	*ptr;

	ptr = map_zc;
	if (*ptr == '-' && ft_isdigit(*(ptr + 1)) == 1)
		ptr++;
	while (*ptr && *ptr != ',')
	{
		if (ft_isdigit(*ptr) == 0)
		{
			map_ptr->z = 0;
			return (0);
		}
		ptr++;
	}
	map_ptr->z = ft_atoi(map_zc);
	return (1);
}

int		ft_get_map_z_and_color(t_id *id, t_point *map_ptr, char *map_zc)
{
	unsigned long	comma_pos;
	size_t			l_color;

	if (ft_node_check(map_ptr, map_zc) == 0)
		map_ptr->c = id->cfg->def_bc;
	else
	{
		l_color = ft_strlen(map_zc);
		if (ft_memchr(map_zc, ',', l_color) != NULL)
		{
			comma_pos = (char *)ft_memchr(map_zc, ',', l_color) - map_zc;
			map_ptr->c = (unsigned int)ft_strtol(ft_strsub(map_zc,
			(int)(comma_pos + 1), l_color - comma_pos - 1), NULL, 16);
		}
		else
			map_ptr->c = id->cfg->dc->c_grnd;
	}
	return (1);
}

t_point	*ft_map_parse(t_id *id, t_point *map_ptr, char **array, int col)
{
	int j;

	j = 0;
	map_ptr = malloc(sizeof(t_point) * (id->map_w));
	while (j < col)
	{
		map_ptr[j].x = j;
		map_ptr[j].y = id->map_l;
		if (ft_get_map_z_and_color(id, &map_ptr[j], array[j]) == 0)
			ft_exit_error(777);
		if (map_ptr[j].z > id->mp->mh.z)
			id->mp->mh = map_ptr[j];
		if (map_ptr[j].z < id->mp->lh.z)
			id->mp->lh = map_ptr[j];
		j++;
	}
	while (j < id->map_w)
	{
		map_ptr[j].x = j;
		map_ptr[j].y = id->map_l;
		map_ptr[j].z = 0;
		map_ptr[j].c = id->cfg->def_bc;
		j++;
	}
	return (map_ptr);
}

void	ft_read_map_file(t_id *id, char *map_file)
{
	char	*str;
	int		fd;
	char	**arr;
	int		i;
	int		col;

	i = 0;
	fd = open(map_file, O_RDONLY);
	while (ft_get_line(fd, &str) > 0)
	{
		if ((arr = ft_strsplit(str, ' ')) != NULL)
		{
			col = ft_count_col(arr);
			id->map[i] = ft_map_parse(id, id->map[i], arr, col);
			id->map_l++;
			i++;
		}
		else
			ft_exit_error(555);
		ft_free_array_and_str(str, arr);
	}
	close(fd);
}

void	ft_map_read(char *map_file, t_id *id)
{
	ft_check_empty_file(map_file);
	ft_check_map_file(id, map_file);
	id->map = malloc(sizeof(t_point *) * id->map_l);
	id->map_l = 0;
	ft_read_map_file(id, map_file);
	id->mp->tl = id->map[0][0];
	id->mp->tr = id->map[0][id->map_w - 1];
	id->mp->bl = id->map[id->map_l - 1][0];
	id->mp->br = id->map[id->map_l - 1][id->map_w - 1];
}
