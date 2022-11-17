/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 15:27:15 by tzi-qi            #+#    #+#             */
/*   Updated: 2022/10/23 20:17:48 by tzi-qi           ###   ########.fr       */
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

typedef struct s_coor
{
	int	x;
	int	y;
	int	z;
	int	color;
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
	int		nrow;
	int		ncol;
	int		color;
	int		grid_gapsize;
	t_coor	**coors;
	t_coor	center_translation;

}	t_data;

//pasing functions
void	count_row_column(t_data *data, char **argv);

//utilities
void	init_data(t_data *data);
void	grid_gapsize(t_data *data);
double	degtorad(double degree);
int		ft_htoi(char *str);

//algorithm
void	draw_line(t_data *data, t_coor *start, t_coor *end);
void	isometric_rotation(t_data *data, double x_value, double y_value);
void	print_grid_line(t_data *data);
void	translation(t_data *data);
void	center(t_data *data);

//insert_coordinates
void	insert_coordinates_xy(t_data *data, char **argv);
void	insert_coordinates_z(t_data *data, char **argv);
void	malloc_coordinates(t_data *data);
void	colour(t_data *data, char *split, int i, int j);

//main.c
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		remove_everything(t_data *data);
int		keyhook_handler(int keycode, t_data *data);
int		remove_everything(t_data *data);
int		error_checking(int argc, char **argv);

#endif
