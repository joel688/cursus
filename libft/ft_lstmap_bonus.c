/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:55:31 by joakoeni          #+#    #+#             */
/*   Updated: 2022/11/21 14:56:15 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*cell;
	t_list	*newlst;
	void	*tmp;

	newlst = NULL;
	if (!f || !del)
		return (NULL);
	while (lst)
	{
		tmp = (*f)(lst->content);
		cell = ft_lstnew(tmp);
		if (cell == NULL)
		{
			free(tmp);
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, cell);
		lst = lst->next;
	}
	return (newlst);
}
