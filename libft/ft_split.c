/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 14:52:35 by tzi-qi            #+#    #+#             */
/*   Updated: 2022/06/03 13:52:02 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	compare(char s, char c)
{
	if (s == c)
		return (0);
	return (1);
}

static int	number_wd(char *str, char c)
{
	int	i;
	int	number;

	i = 0;
	number = 0;
	while (str[i])
	{
		if (compare(str[i], c))
		{
			number++;
			while (compare(str[i], c) && str[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (number);
}

static int	num_char(char *s, char c)
{
	int	count;

	count = 0;
	while (compare(*s, c) == 1 && *s++ != '\0')
		count++;
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**outcome;
	int		i;
	char	*a;

	if (s == NULL)
		return (NULL);
	a = (char *)s;
	outcome = malloc((number_wd(a, c) + 1) * sizeof(char *));
	if (!outcome)
		return (NULL);
	i = 0;
	while (*a)
	{
		if (compare(*a, c) == 1)
		{
			outcome[i] = ft_substr(a, 0, num_char(a, c));
			a += num_char(a, c);
			i++;
		}
		else
			a++;
	}
	outcome[i] = NULL;
	return (outcome);
}

// int	main(void)
// {
// 	char	s[100] = "tripouille";
// 	char	c = 0;
// 	int		i;
// 	char	**outcome;

// 	i = 0;
// 	outcome = ft_split("tripouille", 0);
	// printf("WHAT: [%s]\n", outcome[1]);
	// for (int i = 0; outcome[i] != NULL; ++i)
	// 	free(outcome[i]);
	// free(outcome);
	// while (outcome[i])
	// {
	// 	printf ("%s\n",outcome[i]);
	// 	printf("%zu\n", ft_strlen(outcome[i]));
	// 	printf("i = %i\n", i);
	// 	i++;
	// }
// }