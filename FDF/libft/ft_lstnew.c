/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 19:33:34 by yskrypny          #+#    #+#             */
/*   Updated: 2016/12/08 19:33:43 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new_elem;

	new_elem = malloc(sizeof(t_list));
	if (new_elem != NULL)
	{
		if (content == NULL)
		{
			new_elem->content = NULL;
			new_elem->content_size = 0;
		}
		else
		{
			new_elem->content = (void *)malloc(content_size);
			new_elem->content = ft_memcpy(new_elem->content,
			content, content_size);
			new_elem->content_size = content_size;
		}
		new_elem->next = NULL;
	}
	return (new_elem);
}
