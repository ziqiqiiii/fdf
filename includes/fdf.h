/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 15:27:15 by tzi-qi            #+#    #+#             */
/*   Updated: 2022/09/24 19:11:45 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "get_next_line.h"
# include "libft.h"

# include <stdio.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		xstart;
	int		ystart;
	int		xend;
	int		yend;
	int		color;
	int		nrow;
	int		ncol;
	char	**map;

}	t_data;

//pasing functions
void	draw_map(t_data *data, char **argv);
void	count_row_column(t_data *data, char **argv);
void	count_column(t_data *data, char	*gnl);
void	init_data(t_data *data);

//main.c
// void	draw_grid(t_data *data, int xstart, int ystart, int xend, int yend, int n_row, int n_column, int color);
// void	draw_line(t_data *data, int xstart, int ystart, int xend, int yend,int color);
// void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
// int		cal_coords(int start, int end);

#endif
