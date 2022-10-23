/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:56:36 by tzi-qi            #+#    #+#             */
/*   Updated: 2022/10/23 18:16:51 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

void	translation(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (j < data->nrow)
	{
		i = 0;
		while (i < data->ncol)
		{
			data->coors[j][i].x += data->center_translation.x;
			data->coors[j][i].y += data->center_translation.y + 200;
			i++;
		}
		j++;
	}
}

void	center(t_data *data)
{
	int	min_x;
	int	max_x;
	int	min_y;
	int	max_y;

	min_x = data->coors[data->nrow - 1][0].z;
	max_x = data->coors[0][data->ncol - 1].z;
	min_y = data->coors[0][0].y;
	max_y = data->coors[data->nrow - 1][data->ncol - 1].y;
	data->center.x = (max_x - min_x) / 2 + min_x;
	data->center.y = (max_y - min_y) / 2;
	data->center_translation.x = 1920 - (max_x - min_x);
	data->center_translation.x /= 2;
	data->center_translation.x -= min_x;
	data->center_translation.y = 1080 - (max_y - min_y);
	data->center_translation.y /= 2;
	translation(data);
}

void	draw_line(t_data *data, t_coor *start, t_coor *end)
{
	double	dx;
	double	dy;
	double	pixelx;
	double	pixely;
	int		pixels;

	dx = end->x - start->x;
	dy = end->y - start->y;
	pixels = sqrt((dx * dx) + (dy * dy));
	dx /= pixels;
	dy /= pixels;
	pixelx = start->x;
	pixely = start->y;
	while (pixels > 0)
	{
		data->color = end->color;
		if ((pixelx > 0 && pixelx < 1920) && (pixely > 0 && pixely < 1080))
			my_mlx_pixel_put(data, pixelx, pixely, data->color);
		pixelx += dx;
		pixely += dy;
		--pixels;
	}
}

//draw_line() is basically using pythagorus theorum, 
//That's why sqrt is being used.
//dx /= pixels is just ratio how much needed to move along the x-axis
//dy /= pixels do the same with y-aixs

void	print_grid_line(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (i < data->nrow)
	{
		j = 0;
		while (j < data->ncol)
		{
			if (i != (data->nrow - 1))
				draw_line(data, &data->coors[i][j], &data->coors[i + 1][j]);
			if (j != (data->ncol - 1))
				draw_line(data, &data->coors[i][j], &data->coors[i][j + 1]);
			j++;
		}
		i++;
	}
}

//[row][column]
void	isometric_rotation(t_data *data, double x_value, double y_value)
{
	int	j;
	int	i;
	int	x;
	int	y;

	j = 0;
	while (j < data->nrow)
	{
		i = 0;
		while (i < data->ncol)
		{
			x = data->coors[j][i].x;
			y = data->coors[j][i].y;
			data->coors[j][i].x = x * cos(x_value) - y * sin(y_value);
			data->coors[j][i].y = x * sin(x_value) + y * cos(y_value);
			if (data->coors[j][i].z != 0)
				data->coors[j][i].y -= (data->coors[j][i].z * \
				(data->grid_gapsize / 1.5));
			i++;
		}
		j++;
	}
	center(data);
	print_grid_line(data);
}
