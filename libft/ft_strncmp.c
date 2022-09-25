/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:56:30 by tzi-qi            #+#    #+#             */
/*   Updated: 2022/06/02 17:50:05 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int	a;

	a = 0;
	while (a < n)
	{
		if (s1[a] != '\0' && (s1[a] == s2[a]))
			a++;
		else
			return ((unsigned char)s1[a] - (unsigned char)s2[a]);
	}
	return (0);
}
