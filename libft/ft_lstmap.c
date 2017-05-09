/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 19:33:13 by yskrypny          #+#    #+#             */
/*   Updated: 2016/12/08 19:33:21 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new_list;
	t_list *ret_list;

	if (lst != NULL && f != NULL)
	{
		new_list = f(lst);
		ret_list = new_list;
		lst = lst->next;
		while (lst != NULL)
		{
			new_list->next = f(lst);
			lst = lst->next;
			new_list = new_list->next;
		}
		return (ret_list);
	}
	return (NULL);
}
