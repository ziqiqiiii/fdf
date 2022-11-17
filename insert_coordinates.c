/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_coordinates.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 15:18:35 by tzi-qi            #+#    #+#             */
/*   Updated: 2022/10/23 20:14:36 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

void	colour(t_data *data, char *split, int i, int j)
{
	if (ft_strchr(split, ','))
		data->coors[j][i].color = ft_htoi(ft_strchr(split, ',') + 3);
	else
		data->coors[j][i].color = 0x00E8D09B;
}

static void	loop_spilt_z(t_data *data, char **split, int i, int j)
{
	while (*split)
	{
		data->coors[j][i].z = ft_atoi(*split);
		colour(data, *split, i, j);
		i++;
		free(*split);
		split++;
	}
}

void	insert_coordinates_z(t_data *data, char **argv)
{
	int		fd;
	char	*gnl;
	char	**split;
	int		i;
	int		j;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return ;
	j = 0;
	while (1)
	{
		gnl = get_next_line(fd);
		if (gnl == NULL)
			break ;
		split = ft_split(gnl, ' ');
		i = 0;
		loop_spilt_z(data, split, i, j);
		j++;
	}
	close (fd);
}

void	insert_coordinates_xy(t_data *data, char **argv)
{
	int		i;
	int		j;

	grid_gapsize(data);
	j = 0;
	while (j < data->nrow)
	{
		i = 0;
		while (i < data->ncol)
		{
			data->coors[j][i].x = i * data->grid_gapsize;
			data->coors[j][i].y = j * data->grid_gapsize;
			i++;
		}
		j++;
	}
	insert_coordinates_z(data, argv);
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
