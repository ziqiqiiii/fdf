/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:59:20 by tzi-qi            #+#    #+#             */
/*   Updated: 2022/10/22 16:42:05 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	count_row_column(t_data *data, char **argv)
{
	int		fd;
	char	*gnl;
	char	**split;

	fd = open(argv[1], O_RDONLY);
	while (1)
	{
		gnl = get_next_line(fd);
		if (gnl == NULL)
			break ;
		split = ft_split(gnl, ' ');
		while (*split)
		{
			data->ncol++;
			free(*split);
			split++;
		}
		free(gnl);
		data->nrow++;
		// printf("row %i col %i\n", data->nrow, data->ncol);
	}
	data->ncol = data->ncol / data->nrow;
	close(fd);
}

// void printing_error(t_data *data, char *error)
// {
// 	if (data != NULL)
// 	{
// 		free(fdf->map)
// 	}
// }