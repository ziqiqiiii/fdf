/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 15:27:15 by tzi-qi            #+#    #+#             */
/*   Updated: 2022/10/22 16:40:53 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"

# include <stdio.h>

typedef struct s_coor
{
	int	x;
	int	y;
	int	z;
}	t_coor;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		linelen;
	int		end;
}	t_img;

typedef struct s_data
{
	t_img	*img;
	void	*mlx;
	void	*mlx_win;
	int		color;
	int		nrow;
	int		ncol;
	int		grid_gapsize;
	t_coor	**coors;
	t_coor	center;
	t_coor	center_translation;

}	t_data;

//pasing functions
void	count_row_column(t_data *data, char **argv);

//initialise
void	init_data(t_data *data);
void	input_value_color(t_data *data, int color);
void	malloc_coordinates(t_data *data);
void	grid_gapsize(t_data *data);

//algorithm
void	draw_line(t_data *data, t_coor *start, t_coor *end);
void	insert_coordinates_xy(t_data *data, char **argv);
void	insert_coordinates_z(t_data *data, char **argv);
void	isometric_rotation(t_data *data);
void	print_grid_line(t_data *data);

//main.c
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif
