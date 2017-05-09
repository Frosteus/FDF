/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 19:32:17 by yskrypny          #+#    #+#             */
/*   Updated: 2016/12/08 19:32:25 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;

	tmp = *alst;
	if (tmp != NULL && del != NULL)
	{
		while (*alst)
		{
			(*del)((*alst)->content, (*alst)->content_size);
			free(*alst);
			(*alst) = (*alst)->next;
		}
		tmp = NULL;
	}
}
