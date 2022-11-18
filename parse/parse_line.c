/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:27:29 by otmallah          #+#    #+#             */
/*   Updated: 2022/11/18 18:47:42 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	add_all_path_of_texture(char *line, t_path *path, int i, char *str)
{
	if (ft_strstr2(line, "NO", 2))
		get_no(line, path);
	else if (ft_strstr2(line, "SO", 2))
		get_so(line, path);
	else if (ft_strstr2(line, "WE", 2))
		get_we(line, path);
	else if (ft_strstr2(line, "EA", 2))
		get_ea(line, path);
	else if (ft_strstr2(line, "F", 1))
		get_f(line, path);
	else if (ft_strlen(line) > 1 && ft_strstr2(line, "C", 1))
		get_c(line, path);
	else if (str[i] == '1' || str[i] == '0')
		return (check_path_of_texture(path, str, path->parse));
	else if (str[i] != '\0')
	{
		write (2, "there is something wrong in map\n", 33);
		exit(0);
	}
	return (0);
}

void	get_path(int fd, t_path *path)
{
	char		*line;
	int			i;
	static int	a;
	char		*str;

	i = 0;
	line = get_next_line(fd);
	if (line == NULL)
		return ;
	str = ft_strdup(line);
	while ((line[i] == 32 || line[i] == '\t' || line[i] == '\r'))
		i++;
	path->parse = a;
	if (add_all_path_of_texture((line + i), path, i, line) == 1)
	{
		free(line);
		free(str);
		return ;
	}
	a++;
	free(line);
	free(str);
	get_path(fd, path);
}

int	calcul_x_map(char **map)
{
	int	n;
	int	i;
	int	j;

	i = 0;
	n = ft_strlen(map[0]);
	while (map[i])
	{
		j = ft_strlen(map[i]);
		if (n < j)
			n = j;
		i++;
	}
	return (n);
}

void	first_line(t_path *path)
{
	int	i;

	i = 0;
	if (!path->map[0])
		exit(0);
	path->map_x = calcul_x_map(path->map);
	while (path->map[0][i])
	{
		if ((path->map[0][i] == 32 || path->map[0][i] == '\t'
			|| path->map[0][i] == '\r') || path->map[0][i] == '1')
			i++;
		else
		{
			write(2, "error\n", 7);
			exit(0);
		}
	}
}

void	last_line(t_path *path, int i)
{
	int	j;

	j = 0;
	while (path->map[i][j])
	{
		if ((path->map[i][j] == 32 || path->map[i][j] == '\t'
			|| path->map[i][j] == '\r') || path->map[i][j] == '1')
			j++;
		else
		{
			write(2, "error\n", 7);
			exit(0);
		}
	}
}
