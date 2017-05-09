/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_transformation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 18:37:27 by yskrypny          #+#    #+#             */
/*   Updated: 2017/05/07 18:37:28 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_transform_point(t_id *id, t_point *point)
{
	int i;

	i = 0;
	while (i < id->f_cnt)
	{
		((void (*)(t_id *, t_point *))id->func[i].func)(id, point);
		i++;
	}
}

void	ft_arr_function_check_flag_add(t_id *id)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < FUNC_COUNT)
	{
		if (id->trf[i].flag == 1)
		{
			id->func[j].func = id->trf[i].func;
			j++;
		}
		i++;
	}
}

void	ft_make_arr_of_transform_functions(t_id *id)
{
	int i;

	i = 0;
	if (id->func != NULL)
	{
		free(id->func);
		id->f_cnt = 0;
	}
	while (i < FUNC_COUNT)
	{
		if (id->trf[i].flag == 1)
			id->f_cnt++;
		i++;
	}
	if ((id->func = malloc(sizeof(t_func) * id->f_cnt)) == NULL)
		ft_exit_error(555);
	ft_arr_function_check_flag_add(id);
}
