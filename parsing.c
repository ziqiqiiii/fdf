/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:59:20 by tzi-qi            #+#    #+#             */
/*   Updated: 2022/09/24 19:07:20 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_data(t_data *data)
{
	data->nrow = 0;
	data->ncol = 0;
}

void	count_column(t_data *data, char	*gnl)
{
	while (*gnl != '\0' && *gnl != '\n')
	{
		if (ft_isdigit(*gnl) == 1 || *gnl == '-')
		{	
			if (*gnl == '-')
				gnl++;
			while (ft_isdigit(*gnl) == 1)
				gnl++;
			data->ncol++;
		}
		if (*gnl == ',')
		{	
			while (*gnl != ' ')
				gnl++;
		}
		gnl++;
		while (*gnl == ' ')
			gnl++;
	}
}

void	count_row_column(t_data *data, char **argv)
{
	int		fd;
	char	*gnl;

	fd = open(argv[1], O_RDONLY);
	while (1)
	{
		gnl = get_next_line(fd);
		if (gnl == NULL)
			break ;
		count_column(data, gnl);
		data->nrow++;
	}
	data->ncol = data->ncol / data->nrow;
	// printf("eu lee likes to stir the pot\n");
	// printf("why he check grammar and spelling mistake\n");
	close(fd);
}

void	draw_map(t_data *data, char **argv)
{
	char	**maps;
	int		i;
	int		fd;
	char	*gnl;

	i = 0;
	maps = ft_calloc((data->nrow + 1), sizeof(char *));
	fd = open(argv[1], O_RDONLY);
	while (i < data->nrow)
	{
		gnl = get_next_line(fd);
		maps[i] = ft_strdup(gnl);
		i++;
	}
	data->map = maps;
}
