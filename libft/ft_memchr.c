/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 22:19:51 by tzi-qi            #+#    #+#             */
/*   Updated: 2022/05/24 22:29:40 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			a;
	unsigned char	*s_1;
	unsigned char	s_2;

	s_1 = (unsigned char *)s;
	s_2 = (unsigned char )c;
	a = 0;
	while (a < n)
	{
		if (s_1[a] == s_2)
			return (&s_1[a]);
		a++;
	}
	return (NULL);
}
