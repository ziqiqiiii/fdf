/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 20:03:14 by tzi-qi            #+#    #+#             */
/*   Updated: 2022/05/24 19:07:06 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dest_len;

	i = 0;
	j = 0;
	dest_len = ft_strlen(dest);
	if (size == 0)
		return (ft_strlen(src));
	if (size - 1 >= ft_strlen(dest))
	{
		while (dest[i])
			i++;
		while (src[j] && (i < size - 1))
		{
			dest[i] = src[j];
			i++;
			j++;
		}
		dest[i] = '\0';
		return (dest_len + ft_strlen(src));
	}
	else
		return (ft_strlen(src) + size);
	return (0);
}

// #include <stdio.h>
// #include <string.h>

// int	main()
// {
//     char dest[100] = "This is a potentially long";
//     char src[] = "string";
// 	char mydest[100] = "This is a potentially long";
// 	char mysrc[] = "string";
//     int their_return;
// 	int my_return;

// 	printf("strlen of dest before fucntion %lu\n",strlen(dest));
// 	printf("strlen of src before function %lu\n", strlen(src));
//     their_return = strlcat(dest,src, 0);
// 	my_return = ft_strlcat(mydest, mysrc, 0);
// 	printf("size of dest : %lu\n",sizeof(dest));
// 	printf("the return value of their strlcat 		: %d\n", their_return);
// 	printf("the return value of my strlcat 			: %d\n", my_return);
// 	printf("after their strlcat the dest is 		: [%s]\n", dest);
// 	printf("after my strlcat the dest is 			: [%s]\n", mydest);
// }