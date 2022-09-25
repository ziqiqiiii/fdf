/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 22:00:14 by tzi-qi            #+#    #+#             */
/*   Updated: 2022/05/25 17:12:24 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = ft_strlen(needle);
	if (!*needle)
		return ((char *)haystack);
	while (haystack[0] && len > 0)
	{
		if (len >= i && ft_memcmp((char *)haystack, (char *)needle, i) == 0)
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
