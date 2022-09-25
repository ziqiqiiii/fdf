/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maincopy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 16:29:59 by tzi-qi            #+#    #+#             */
/*   Updated: 2022/09/24 19:28:25 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include "fdf.h"

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

// typedef struct s_data
// {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// 	int		xstart;
// 	int		ystart;
// 	int		xend;
// 	int		yend;
// 	int		color;

// }	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * 4);
	*(unsigned int *)dst = data->color;
}

void	draw_line(t_data *data)
{
	double	dx;
	double	dy;
	double	pixelx;
	double	pixely;
	int		pixels;

	dx = data->xend - data->xstart;
	printf("the value of dx = [%f]\n", dx);
	dy = data->yend - data->ystart;
	printf("the value of dy = [%f]\n", dy);
	pixels = sqrt((dx * dx) + (dy * dy));
	dx /= pixels;
	dy /= pixels;
	pixelx = data->xstart;
	pixely = data->ystart;
	while (pixels > 0)
	{
		my_mlx_pixel_put(data, pixelx, pixely);
		pixelx += dx;
		pixely += dy;
		--pixels;
	}
}

//draw_line() is basically using pythagorus theorum, 
//That's why sqrt is being used.
//dx /= pixels is just ratio how much needed to move along the x-axis
//dy /= pixels do the same with y-aixs

void	draw_grid(t_data *data, int n_row, int n_coloumn)
{	
	double	dx;
	double	dy;
	double	dr;
	double	dc;
	double	a;

	dx = data->xend - data->xstart;
	printf("the value of dx = [%f]\n", dx);
	dy = data->yend - data->ystart;
	printf("the value of dy = [%f]\n", dy);
	dr = dy / n_row;
	printf("the value of dr = [%f]\n", dr);
	dc = dx / n_coloumn;
	printf("the value of dc = [%f]\n", dc);
	a = data->xstart;
	while (a <= data->xend)
	{
		draw_line(data);
		a += dc;
	}
	a = data->ystart;
	while (a <= data->yend)
	{
		draw_line(data);
		a += dr;
	}
}

// since i'm putting all the coordinates(xy start, xy end)
//need another function/ somewhere else to input the data
void	input_value_start(t_data *data, int xstart, int ystart)
{
	data->xstart = xstart;
	data->ystart = ystart;
}

void	input_value_end(t_data *data, int xend, int yend)
{
	data->xend = xend;
	data->yend = yend;
}

void	input_value_color(t_data *data, int color)
{
	data->color = color;
}

int	main(int argc, char *argv[])
{
	void	*mlx;
	void	*mlx_win;
	t_data	img0;
	// int		fd;
	// char	*gnl;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img0.img = mlx_new_image(mlx, 1920, 1080);
	img0.addr = mlx_get_data_addr(img0.img, &img0.bits_per_pixel, &img0.line_length, &img0.endian);
	input_value_color(&img0, 0x00F5C9A6);
	input_value_start(&img0, 500, 100);
	input_value_end(&img0, 1500, 900);
	// if (argc != 2)
	// {
	// 	ft_putstr_fd("Error: Wrong number of arguments\n", 2);
	// 	return (0);
	// }
	// else
	// {
	// 	fd = open(argv[1], O_RDONLY);
	// 	while (1)
	// 	{
	// 		gnl = get_next_line(fd);
	// 		if (gnl == NULL)
	// 			break ;
	// 		printf("%s\n", gnl);
	// 	}
	// }
	// draw_line(&img0, 500, 300, 1500, 300, 0x00CEA866);
	// draw_line(&img0, 500, 900, 1500, 900, 0x00ADD0CA);
	// draw_line(&img0, 500, 300, 500, 900, 0x00CEEEA5);
	// draw_line(&img0);
	draw_grid(&img0, 10, 10);
	mlx_put_image_to_window(mlx, mlx_win, img0.img, 0, 0);
	mlx_loop(mlx);
	// return (0);
}
