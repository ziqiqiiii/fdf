/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:10:29 by tzi-qi            #+#    #+#             */
/*   Updated: 2022/06/02 17:45:57 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	int				i;
	unsigned char	*a;

	i = 0;
	a = (unsigned char *)str;
	while (n--)
		a[i++] = (unsigned char)c;
	return (a);
}

// #define  BUF_SIZE  20
// int main(void)
// {
//    char buffer[BUF_SIZE + 1] = "aaaaaaa\000aaaaaaa";
//    char *string; 
//    int i = 0;
//    ft_memset(buffer, 70, 5);
//     printf("%s\n", buffer);
//     while (i < 21)
//         printf("%c", buffer[i++]);

//    string = (char *) ft_memset(buffer, '9', 10);
//    printf("\nBuffer contents: %s\n", string);
//    ft_memset(buffer+10, 'B',10);
//    printf("\nBuffer contents: %s\n", buffer);
// }