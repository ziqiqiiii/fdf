/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:59:20 by tzi-qi            #+#    #+#             */
/*   Updated: 2022/10/22 22:40:58 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	printing_error(t_data *data, char *error)
{
	if (data)
		free(data);
	write(1, error, ft_strlen(error));
	exit(-1);
}

void	count_row_column(t_data *data, char **argv)
{
	int		fd;
	char	*gnl;
	char	**split;
	int		i;
	int		a;

	a = 1;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return ;
	while (1)
	{
		gnl = get_next_line(fd);
		if (gnl == NULL)
			break ;
		split = ft_split(gnl, ' ');
		i = 0;
		while (*split)
		{
			i++;
			free(*split);
			split++;
		}
		if (data->ncol == 0)
			data->ncol = i;
		else
		{
			data->ncol += i;
			if (data->ncol / a != i)
			{
				ft_putstr_fd("Error: invalid number of lines\n", 2);
				exit (-1);
			}
		}
		free(gnl);
		data->nrow++;
		a++;
		// printf("row %i col %i\n", data->nrow, data->ncol);
	}
	data->ncol = data->ncol / data->nrow;
	close(fd);
}
