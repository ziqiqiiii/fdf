/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 16:29:59 by tzi-qi            #+#    #+#             */
/*   Updated: 2022/09/25 17:46:17 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * 4);
	*(unsigned int *)dst = color;
}

int	cal_coords(int start, int end)
{
	return (end - start);
}

void	draw_line(t_data *data, int xstart, int ystart, int xend, int yend,int color)
{
	double	dx;
	double	dy;
	double	pixelx;
	double	pixely;
	int		pixels;

	dx = xend - xstart;
	dy = yend - ystart;
	pixels = sqrt((dx * dx) + (dy * dy));
	dx /= pixels;
	dy /= pixels;
	pixelx = xstart;
	pixely = ystart;
	while (pixels > 0)
	{
		my_mlx_pixel_put(data, pixelx, pixely, color);
		pixelx += dx;
		pixely += dy;
		--pixels;
	}
}

void	draw_grid(t_data *data, int xstart, int ystart, int xend, int yend, int n_row, int n_column, int color)
{	
	double	dx;
	double	dy;
	double	dr;
	double	dc;
	double	a;

	dx = xend - xstart;
	dy = yend - ystart;
	dr = dy / n_row;
	dc = dx / n_column;
	a = xstart;
	while (a <= xend)
	{
		draw_line(data, a, ystart, a, yend, color);
		a += dc;
	}
	a = ystart;
	while (a <= yend)
	{
		draw_line(data, xstart, a, xend, a, color);
		a += dr;
	}
}
//draw_line() is basically using pythagorus theorum, 
//That's why sqrt is being used.
//dx /= pixels is just ratio how much needed to move along the x-axis
//dy /= pixels do the same with y-aixs


int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img0;
	// t_data	data;
	// int i;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img0.img = mlx_new_image(mlx, 1920, 1080);
	img0.addr = mlx_get_data_addr(img0.img, &img0.bits_per_pixel, &img0.line_length, &img0.endian);
	// if (argc != 2)
	// {
	// 	ft_putstr_fd("Error: Wrong number of arguments\n", 2);
	// 	return (0);
	// }
	// else
	// {
	// 	init_data(&data);
	// 	count_row_column(&data, argv);
	// }
	// i = 0;
	// draw_map(&data, argv);
	// while (i < data.nrow)
	// {
	// 	printf("%s", data.map[i]);
	// 	i++;
	// }
	// draw_line(&img0, 500, 300, 1500, 300, 0x00CEA866);
	// draw_line(&img0, 500, 900, 1500, 900, 0x00ADD0CA);
	// draw_line(&img0, 500, 300, 500, 900, 0x00CEEEA5);
	// draw_line(&img0, 1500, 300, 1500, 900, 0x0095D6D0);
	draw_grid(&img0, 500, 100, 1500, 900, 30, 20, 0x00EBDEA9);
	mlx_put_image_to_window(mlx, mlx_win, img0.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
