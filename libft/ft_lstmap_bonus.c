/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:55:31 by joakoeni          #+#    #+#             */
/*   Updated: 2022/11/18 17:25:54 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*cell;
	t_list	*newlst;

	newlst = NULL;
//	if (f == NULL || *f == NULL || del == NULL || lst == NULL)
//		return (NULL);
	while (lst)
	{
		cell = ft_lstnew((*f)(lst->content));
		if (cell == NULL)
		{
			del(cell->content);
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, cell);
		lst = lst->next;
	}
	return (newlst);
}
