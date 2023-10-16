/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:38:32 by pli               #+#    #+#             */
/*   Updated: 2022/03/17 14:48:15 by pli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*list;

	if (!lst || !f)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	if (!new)
		return (NULL);
	list = new;
	lst = lst->next;
	if (lst)
	{
		while (lst)
		{
			new = ft_lstnew(f(lst->content));
			if (!(new))
			{
				ft_lstclear(&list, del);
				return (NULL);
			}
			ft_lstadd_back(&list, new);
			lst = lst->next;
		}
	}
	return (list);
}
