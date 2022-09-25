/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 16:33:58 by tzi-qi            #+#    #+#             */
/*   Updated: 2022/06/02 18:22:38 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*outcome;

	i = 0;
	if (s == NULL)
		return (NULL);
	outcome = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!outcome)
		return (NULL);
	while (s[i])
	{
		outcome[i] = f(i, s[i]);
		i++;
	}
	outcome[i] = '\0';
	return (outcome);
}
