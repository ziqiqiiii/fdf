/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 22:50:08 by tzi-qi            #+#    #+#             */
/*   Updated: 2022/05/24 23:00:25 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*s1;
	char	s2;
	int		a;

	s1 = (char *)s;
	s2 = (char )c;
	a = ft_strlen(s);
	while (a > 0)
	{
		if (s1[a] == s2)
			return (&s1[a]);
		a--;
	}
	if (s1[a] == s2)
		return (&s1[a]);
	return (NULL);
}
