/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 16:29:59 by tzi-qi            #+#    #+#             */
/*   Updated: 2022/10/22 22:23:23 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img->addr + (y * data->img->linelen + x * 4);
	*(unsigned int *)dst = color;
}

int	remove_everything(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img->img);
	mlx_destroy_window(data->mlx, data->mlx_win);
	while (data->nrow--)
		free(data->coors[data->nrow]);
	free(data->coors);
	free(data->img);
	free(data);
	exit(0);
}
//the 2D array of the coordinates 
//the img
//the window
//every point have thier own coordinate (x, y z)
//draw line is used to connec the dots
//rotation/ transformation/ is apply to points and then only draw lines
// 	// data->ncol = i + 1;
// }

int	keyhook_handler(int keycode, t_data *data)
{
	if (keycode == 53)
		remove_everything(data);
	return (0);
}

int error_checking(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd("Error: Wrong number of arguments\n", 2);
		return (0);
	}
	else if (ft_strnstr(argv[1], ".fdf", ft_strlen(argv[1])) == NULL)
	{
		ft_putstr_fd("Error: Plsease provide a valide file\n", 2);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	*img;

	if (error_checking(argc, argv) == 0)
		return (0);
	img = malloc(sizeof(t_data));
	init_data(img);
	count_row_column(img, argv);
	img->img = malloc(sizeof(t_img));
	img->mlx = mlx_init();
	img->mlx_win = mlx_new_window(img->mlx, 1920, 1080, "2months");
	img->img->img = mlx_new_image(img->mlx, 1920, 1080);
	img->img->addr = mlx_get_data_addr(img->img->img, &img->img->bpp, \
				&img->img->linelen, &img->img->end);
	malloc_coordinates(img);
	insert_coordinates_xy(img, argv);
	isometric_rotation(img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img->img, 0, 0);
	mlx_key_hook(img->mlx_win, keyhook_handler, img);
	mlx_hook(img->mlx_win, 17, 0, remove_everything, img);
	mlx_loop(img->mlx);
	return (0);
}
