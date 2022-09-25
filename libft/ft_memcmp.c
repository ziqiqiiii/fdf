/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 21:44:05 by tzi-qi            #+#    #+#             */
/*   Updated: 2022/05/24 21:58:41 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			a;
	unsigned char	*s_1;
	unsigned char	*s_2;

	s_1 = (unsigned char *)s1;
	s_2 = (unsigned char *)s2;
	a = 0;
	while (a < n)
	{
		if (s_1[a] != s_2[a])
			return (s_1[a] - s_2[a]);
		a++;
	}
	return (0);
}
