/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:56:21 by tzi-qi            #+#    #+#             */
/*   Updated: 2022/06/01 15:22:33 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_num_count(long n)
{
	if (n < 0)
		return (ft_num_count(n * -1) + 1);
	if (n > 9)
		return (ft_num_count(n / 10) + ft_num_count(n % 10));
	return (1);
}

char	*ft_itoa(int n)
{
	int		count;
	int		index;
	char	*outcome;
	long	num;

	num = (long)n;
	count = ft_num_count(num);
	index = count;
	outcome = malloc(sizeof(char) * (count + 1));
	if (!outcome)
		return (NULL);
	outcome[count] = '\0';
	if (num < 0)
	{
		outcome[0] = '-';
		num *= -1;
		count--;
	}
	while (count > 0)
	{
		outcome[index-- - 1] = (num % 10) + 48;
		num /= 10;
		count--;
	}
	return (outcome);
}

// int main(void)
// {
// 	int before = -2147483648;
// 	char	*after = ft_itoa(before);

// 	printf("before %i\n", before);
// 	printf("after  %s\n", after);

// 	int try_this = -1234;
// 	printf("%d\n", ft_num_count(try_this));
// }