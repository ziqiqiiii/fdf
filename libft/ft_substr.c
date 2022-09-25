/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:55:47 by tzi-qi            #+#    #+#             */
/*   Updated: 2022/06/03 11:47:45 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*temp;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if ((size_t)start > ft_strlen(s))
		len = 0;
	if (len < ft_strlen(s))
		temp = malloc(len * sizeof(char) + 1);
	else
		temp = malloc(ft_strlen(s) * sizeof(char) + 1);
	if (!temp)
		return (NULL);
	while (s[start] && len > 0)
	{
		temp[i] = ((char *)s)[start];
		start++;
		i++;
		len--;
	}
	temp[i] = '\0';
	return (temp);
}

// int	main(void)
// {
// 	char *a = "hello world";

// 	printf("%s\n", ft_substr(a, start, ))

// }