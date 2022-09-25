/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:02:51 by tzi-qi            #+#    #+#             */
/*   Updated: 2022/09/17 22:05:55 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	compare(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (0);
		i++;
	}
	return (1);
}

static char	*what_to_malloc(int start, int end)
{
	char	*outcome;

	if (end > start)
		outcome = ft_calloc((end - start + 2), sizeof(char));
	else
		outcome = ft_calloc((start - end + 2), sizeof(char));
	return (outcome);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*outcome;

	start = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	end = (int)ft_strlen(s1) - 1;
	while (s1[start] && compare(s1[start], (char *)set) == 0)
			start++;
	while (end > 0 && compare(s1[end], (char *)set) == 0)
			end--;
	outcome = what_to_malloc(start, end);
	if (!outcome)
		return (NULL);
	ft_strlcpy(outcome, s1 + start, end - start + 2);
	return (outcome);
}
