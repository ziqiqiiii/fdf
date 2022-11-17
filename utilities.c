/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:17:34 by tzi-qi            #+#    #+#             */
/*   Updated: 2022/10/23 20:00:23 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

double	degtorad(double degree)
{
	return (degree * M_PI / 180);
}

void	init_data(t_data *data)
{
	data->nrow = 0;
	data->ncol = 0;
}

void	grid_gapsize(t_data *data)
{
	if (((1920 / 4) / data->ncol) < 1)
		data->grid_gapsize = 1080 / data->nrow;
	else
		data->grid_gapsize = (1920 / 4) / data->ncol;
}

int	ft_htoi(char *str)
{
	int	num;

	num = 0;
	while (*str)
	{
		num *= 16;
		if (*str >= 'a' && *str <= 'f')
			num += (*str - 'a') + 10;
		else if (*str >= 'A' && *str <= 'F')
			num += (*str - 'A') + 10;
		else
			num += *str - '0';
		str++;
	}
	return (num);
}
