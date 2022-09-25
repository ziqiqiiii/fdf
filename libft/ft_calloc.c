/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:15:12 by tzi-qi            #+#    #+#             */
/*   Updated: 2022/06/02 17:52:13 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*temp;
	size_t	i;

	i = -1;
	if ((count > 65535 || size > 65535) && ((i / count) < size))
		return (NULL);
	temp = malloc(count * size);
	if (!temp)
		return (NULL);
	ft_bzero(temp, count * size);
	return (temp);
}
