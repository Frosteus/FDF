/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 14:18:31 by yskrypny          #+#    #+#             */
/*   Updated: 2017/03/09 14:18:35 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_fd_lst	*ft_lst_new_node(int fd)
{
	t_fd_lst *new_node;

	new_node = malloc(sizeof(t_fd_lst));
	if (new_node != NULL)
	{
		new_node->fd = fd;
		new_node->res = NULL;
		new_node->len = 0;
		new_node->next_fd = NULL;
	}
	return (new_node);
}

static t_fd_lst	*ft_add_check_list(t_fd_lst *lst, int fd)
{
	t_fd_lst *lst_ptr;
	t_fd_lst *tmp_node;

	lst_ptr = lst;
	tmp_node = lst;
	while (lst_ptr != NULL)
	{
		if (lst_ptr->fd == fd)
			return (lst_ptr);
		tmp_node = lst_ptr;
		lst_ptr = lst_ptr->next_fd;
	}
	lst_ptr = ft_lst_new_node(fd);
	tmp_node->next_fd = lst_ptr;
	return (lst_ptr);
}

static int		ft_find_line(char **line, char *buff, t_fd_lst *lst, ssize_t rd)
{
	unsigned long	index;
	char			*temp;

	temp = (*line);
	if (ft_memchr(buff, '\n', (size_t)rd) != NULL)
	{
		index = (char *)ft_memchr(buff, '\n', (size_t)rd) - buff;
		buff[index] = '\0';
		(*line) = ft_strjoin(temp, buff);
		free(temp);
		lst->len = rd - index - 1;
		lst->res = ft_strsub(buff, (unsigned int)index + 1, (size_t)lst->len);
		return (1);
	}
	(*line) = ft_strjoin(temp, buff);
	ft_bzero(buff, rd);
	free(temp);
	return (0);
}

int				ft_get_line(const int fd, char **line)
{
	static t_fd_lst	*lst_r;
	t_fd_lst		*lst;
	char			buffer[BUFF_SIZE + 1];
	ssize_t			rd;

	if (fd < 0 || (read(fd, NULL, 0)) == -1 || line == NULL)
		return (-1);
	if (lst_r == NULL)
		lst_r = ft_lst_new_node(fd);
	lst = ft_add_check_list(lst_r, fd);
	ft_bzero(buffer, BUFF_SIZE + 1);
	(*line) = ft_strnew(1);
	if (lst->res != NULL && ft_find_line(line, lst->res, lst, lst->len) == 1)
		return (1);
	while ((rd = read(fd, buffer, BUFF_SIZE)) != 0)
	{
		if (rd == -1)
			return (-1);
		if (ft_find_line(line, buffer, lst, rd) == 1)
			return (1);
	}
	lst->res = NULL;
	return (ft_strlen((*line)) == 0 ? 0 : 1);
}
