/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:17:34 by tzi-qi            #+#    #+#             */
/*   Updated: 2022/10/22 13:24:22 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_data(t_data *data)
{
	data->nrow = 0;
	data->ncol = 0;
	input_value_color(data, 0x00F5C9A6);
}

void	input_value_color(t_data *data, int color)
{
	data->color = color;
}

void	grid_gapsize(t_data *data)
{
	if (((1920 / 4) / data->ncol) < 1)
		data->grid_gapsize = 1080 / data->nrow;
	else
		data->grid_gapsize = (1920 / 4) / data->ncol;
}

void	malloc_coordinates(t_data *data)
{
	t_coor	**coors;
	int		i;

	i = 0;
	coors = malloc(sizeof(t_coor *) * data->nrow);
	if (!coors)
		return ;
	while (i < data->nrow)
	{
		coors[i] = malloc(sizeof(t_coor) * data->ncol);
		if (!coors[i])
			return ;
		i++;
	}
	data->coors = coors;
}
