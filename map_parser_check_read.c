/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_check_read.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 17:00:29 by yskrypny          #+#    #+#             */
/*   Updated: 2017/05/07 17:00:30 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_check_empty_file(char *map_file)
{
	int		fd;
	char	buff[2];
	ssize_t	rd;

	if ((fd = open(map_file, O_RDONLY)) < 0)
		ft_exit_error(111);
	rd = read(fd, buff, 2);
	if (rd <= 0)
		ft_exit_error(113);
	close(fd);
}

void	ft_check_map_file(t_id *id, char *map_file)
{
	int		check;
	char	*str;
	int		fd;
	char	**array;
	int		width;

	fd = open(map_file, O_RDONLY);
	while ((check = ft_get_line(fd, &str)) > 0)
	{
		if ((array = ft_strsplit(str, ' ')) != NULL)
		{
			if ((width = ft_count_col(array)) > id->map_w)
				id->map_w = width;
		}
		else
			ft_exit_error(555);
		ft_free_array_and_str(str, array);
		id->map_l++;
	}
	if (id->map_w == 0 && check == 0)
		ft_exit_error(114);
	if (check < 0)
		ft_exit_error(112);
	close(fd);
}

int		ft_count_col(char **array)
{
	char	**arr_ptr;
	int		col;

	col = 0;
	arr_ptr = array;
	while (arr_ptr[col])
		col++;
	return (col);
}

void	ft_free_array_and_str(char *str, char **array)
{
	char **ptr;

	free(str);
	ptr = array;
	while (*ptr != NULL)
	{
		free(*ptr);
		ptr++;
	}
}
