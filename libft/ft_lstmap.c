/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:08:17 by tzi-qi            #+#    #+#             */
/*   Updated: 2022/06/06 13:22:46 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*new_list;

	if (lst == NULL)
		return (NULL);
	new_list = ft_lstnew(f(lst->content));
	if (!new_list)
		return (NULL);
	temp = new_list;
	lst = lst->next;
	while (lst != NULL)
	{	
		new_list->next = ft_lstnew(f(lst->content));
		if (new_list->next == NULL)
		{
			ft_lstclear(&lst, del);
			return (NULL);
		}
		new_list = new_list->next;
		lst = lst->next;
	}
	return (temp);
}
