/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:03:03 by tzi-qi            #+#    #+#             */
/*   Updated: 2022/07/23 13:33:52 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	check_buf(char *buf, int count)
{
	int	i;

	i = 0;
	if (!buf)
		return (0);
	while (count > 0 && buf[i] != '\n' && buf[i] != '\0')
	{
		i++;
		count--;
	}
	return (i);
}

int	num_of_line(char *buf)
{
	int	alpha;
	int	i;

	i = 0;
	alpha = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '\n')
			alpha++;
		i++;
	}
	return (alpha);
}

char	*too_easy_project(char buf[1024][999999999], int fd)
{
	int		i;
	char	*substr;
	char	*join;

	join = ft_substr(buf[fd], 0, check_buf(buf[fd], ft_strlen(buf[fd])) + 1);
	i = check_buf(buf[fd], ft_strlen(buf[fd]));
	substr = ft_substr(buf[fd], i + 1, ft_strlen(buf[fd]) - i - 1);
	ft_strlcpy(buf[fd], substr, ft_strlen(substr) + 1);
	free(substr);
	return (join);
}

char	*get_next_line(int fd)
{
	static char	buf[1024][999999999];
	char		read_buf[BUFFER_SIZE + 1];
	int			num;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE < 1)
		return (NULL);
	read_buf[BUFFER_SIZE] = '\0';
	num = read(fd, read_buf, BUFFER_SIZE);
	if (num <= 0 && *buf[fd] == '\0')
		return (NULL);
	read_buf[num] = '\0';
	ft_strcat(buf[fd], read_buf);
	if (num_of_line(buf[fd]) < 2)
	{
		while (check_buf(read_buf, ft_strlen(read_buf)) == ft_strlen(read_buf))
		{
			num = read(fd, read_buf, BUFFER_SIZE);
			if (num <= 0)
				break ;
			read_buf[num] = '\0';
			ft_strcat(buf[fd], read_buf);
		}
	}
	return (too_easy_project(buf, fd));
}

// int main()
// {
// 	int		i;
//     int     fd;
//     char    *buf;
//
// 	i = 1;
//     fd = open("try1.txt", O_RDONLY);

// 	buf = get_next_line(fd);
// 	while (buf != NULL)
// 	{
// 		printf("\nreturn of gnl %i: %s\n\n\n",i, buf);
// 		free(buf);
// 		buf = get_next_line(fd);
// 		i++;
// 	}
// 	printf("\nreturn of gnl %i: %s\n\n\n",i, buf);

//     close(fd);
// }