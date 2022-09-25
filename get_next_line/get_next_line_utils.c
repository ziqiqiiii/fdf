/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:04:54 by tzi-qi            #+#    #+#             */
/*   Updated: 2022/07/21 17:04:54 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && (i < (size - 1)))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (i);
}

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

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
