/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:18:25 by otmallah          #+#    #+#             */
/*   Updated: 2022/11/18 18:47:21 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	size_map(int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	return (i);
}

int	map_in_table(char *line, t_path *path, int i)
{
	int	a;

	a = 0;
	if (!line)
	{
		if (i == 1)
			path->map[0] = NULL;
		else
			path->map[i] = NULL;
		return (-1);
	}
	while (line[a] == 32 || line[a] == '\t')
		a++;
	if (!line[0])
	{
		write(2, "error\n", 7);
		exit(0);
	}
	return (a);
}

void	put_map_in_table(int fd, t_path *path)
{
	char		*line1;
	int			a;
	static int	i;

	i++;
	a = 0;
	line1 = get_next_line(fd);
	a = map_in_table(line1, path, i);
	if (a == -1)
		return ;
	if (line1[a] != '\0' && (line1[a] != '1'
			|| line1[ft_strlen(line1) - 1] != '1')
		&& (line1[ft_strlen(line1) - 1] != ' '
			&& line1[ft_strlen(line1) - 1] != '\t' ))
	{
		write(2, "error\n", 7);
		exit(0);
	}
	path->map[i] = ft_strdup(line1);
	if (i == path->map_y - 1)
		path->map[path->map_y] = NULL;
	free(line1);
	put_map_in_table(fd, path);
}

void	get_c(char *str, t_path *path)
{
	path->tab[5] += 1;
	check_range(str, path);
	path->ceilling_color = ft_strdup(str);
}

void	check_map_it_is_valid(char *str, t_path *path)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd > 0)
	{
		path->map_y = size_map(fd);
		if (path->map_y == 0)
			path->map_y = 1;
		path->map = (char **)malloc(sizeof(char *) * path->map_y);
		close(fd);
		fd = open(str, O_RDONLY);
		get_path(fd, path);
		check_duplicate(path);
		put_map_in_table(fd, path);
		check_walls(path);
		check_characters(path);
		check_path_xpm(path);
	}
	else
	{
		write(2, "File doesn't exist\n", 20);
		exit(0);
	}
}
