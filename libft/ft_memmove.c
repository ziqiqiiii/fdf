/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 17:18:07 by tzi-qi            #+#    #+#             */
/*   Updated: 2022/06/02 16:24:11 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	if (src < dest)
	{
		while (len--)
			((char *)dest)[len] = ((char *)src)[len];
	}
	else if (src >= dest)
		ft_memcpy(dest, src, len);
	return (dest);
}

// #include <string.h>
// #include <stdio.h>
// int main(void)
// {
// 	char dest1[6] = "hello"; 
// 	char dest2[6] = "hello";
// 	char src1[7] = "worldd";
// 	char src2[7] = "worldd";

// 	memmove(dest1, src1, 6) ;
// 	printf("memmove : %s\n ", dest1);
// 	memcpy(dest2, src2, 6);
// 	printf("memcpy : %s\n ", dest2);
// }