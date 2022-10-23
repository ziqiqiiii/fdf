/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:59:20 by tzi-qi            #+#    #+#             */
/*   Updated: 2022/10/23 17:17:36 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

static void	error_check_rowcolumn(t_data *data, int i, char *gnl)
{
	if (data->ncol == 0)
		data->ncol = i;
	else
	{
		if (data->ncol != i || gnl == NULL)
		{
			ft_putstr_fd("Error: invalid number of lines\n", 2);
			exit (-1);
		}
	}
}

static int	loop_split(char **split)
{
	int	i;

	i = 0;
	while (*split)
	{
		i++;
		free(*split);
		split++;
	}
	return (i);
}

void	count_row_column(t_data *data, char **argv)
{
	int		fd;
	char	*gnl;
	char	**split;
	int		i;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return ;
	while (1)
	{
		gnl = get_next_line(fd);
		if (gnl == NULL)
			break ;
		split = ft_split(gnl, ' ');
		i = loop_split(split);
		error_check_rowcolumn(data, i, gnl);
		free(gnl);
		data->nrow++;
	}
	close(fd);
}
