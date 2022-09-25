/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 11:32:46 by tzi-qi            #+#    #+#             */
/*   Updated: 2022/06/06 11:53:37 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;
	t_list	*current;

	if (!lst)
		return ;
	current = *lst;
	while (current)
	{
		temp = current;
		current = current->next;
		ft_lstdelone(temp, del);
	}
	*lst = NULL;
}
