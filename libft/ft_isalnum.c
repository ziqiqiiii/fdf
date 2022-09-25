/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:38:26 by tzi-qi            #+#    #+#             */
/*   Updated: 2022/05/18 14:38:26 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}

// if (c >= 65 && c <= 90)
//     return (1);
// else if (c >= 97 && c <= 122)
//     return (1);
// else if (c >= '0' && c <= '9')
//     return (1);
// else
//     return (0);
// int main(void) 
//  {
//    char val1 = 's';
//    char val2 = '8';
//    char val3 = '$';
//    if(ft_isalnum(val1))
//    printf("The character is alphanumeric\n");
//    else
//    printf("The character is not alphanumeric\n");
//    if(ft_isalnum(val2))
//    printf("The character is alphanumeric\n");
//    else
//    printf("The character is not alphanumeric");
//    if(ft_isalnum(val3))
//    printf("The character is alphanumeric\n");
//    else
//    printf("The character is not alphanumeric");
//    return 0;
// }