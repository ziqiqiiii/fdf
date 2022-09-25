/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 22:30:11 by tzi-qi            #+#    #+#             */
/*   Updated: 2022/05/24 22:44:00 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*s1;
	char	s2;
	int		a;

	s1 = (char *)s;
	s2 = (char )c;
	a = 0;
	while (s1[a])
	{
		if (s1[a] == s2)
			return (&s1[a]);
		a++;
	}
	if (s1[a] == s2)
		return (&s1[a]);
	return (NULL);
}
