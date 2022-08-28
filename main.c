/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 16:29:59 by tzi-qi            #+#    #+#             */
/*   Updated: 2022/08/28 18:51:42 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

// typedef	struct s_data
// {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// }
// )
// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	void	*img;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "hello world!");
// 	img = mlx_new_image(mlx, 1920, 1080);
// 	mlx_loop(mlx);
// }

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

}t_data;

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "hello world!");
// 	img.img = mlx_new_image(mlx, 1920, 1080);

// 	/*
// 	** After creating an image, we can call `mlx_get_data_addr`, we pass
// 	** `bits_per_pixel`, `line_length`, and `endian` by reference. These will
// 	** then be set accordingly for the *current* data address.
// 	*/
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 								&img.endian);	
// 	mlx_loop(mlx);
// }
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	// t_data	img0;
	t_data	img1;
	// int		i;
	// int		j;
	int		x;
	int		y;

	// i = 0;
	// j = 0;
	x = 1000;
	y = 1000;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	// img0.img = mlx_new_image(mlx, 1920, 1080);
	img1.img = mlx_new_image(mlx, 1920, 1080);
	// img0.addr = mlx_get_data_addr(img0.img, &img0.bits_per_pixel, &img0.line_length, &img0.endian);
	img1.addr = mlx_get_data_addr(img1.img, &img1.bits_per_pixel, &img1.line_length, &img1.endian);
	while (x > 0 && y > 0)
	{
		// my_mlx_pixel_put(&img0, i, j, 0x00CEA866);
		my_mlx_pixel_put(&img1, x, y, 0x0092D7E8);
		x++;
		y--;
	}
	// i = 0;
	// j = 0;
	// while (j < 100 || i < 1000)
	// {
	// 	my_mlx_pixel_put(&img0, i, j, 0x00CEA866);
	// 	// my_mlx_pixel_put(&img1, i, j, 0x00CEA866);
	// 	i++;
	// 	j++;
	// }
	// mlx_put_image_to_window(mlx, mlx_win, img0.img, 0, 0);
	mlx_put_image_to_window(mlx, mlx_win, img1.img, 100, 100);
	mlx_loop(mlx);
}
