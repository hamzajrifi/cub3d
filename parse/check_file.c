/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 02:31:44 by otmallah          #+#    #+#             */
/*   Updated: 2022/11/18 18:57:02 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

bool	check_name_of_file(char *str)
{
	char	*test;

	test = ft_strstr(str + 1, ".cub", 4);
	if (test)
		return (true);
	write(2, "must be '.cub' hh\n", 19);
	exit(0);
}

int	len(char *str, int c)
{
	char	*st;
	int		i;

	st = (char *)str;
	i = 0;
	while (str[i])
	{
		if (st[i] == (unsigned char)c)
			return (i);
		i++;
	}
	return (-1);
}

char	*get_str(char *string, int size)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (size + 1));
	while (i < size)
	{
		str[i] = string[i];
		i++;
	}
	str[i] = '\0';
	free(string);
	return (str);
}

void	add_valid_path(t_path *path, int i, char *str)
{
	int	s;

	if (i == 0)
	{
		s = len(path->east_texture, '\\');
		path->east_texture = ft_strjoin(get_str(path->east_texture, s), str);
	}
	if (i == 1)
	{
		s = len(path->west_texture, '\\');
		path->west_texture = ft_strjoin(get_str(path->west_texture, s), str);
	}
	if (i == 2)
	{
		s = len(path->north_texture, '\\');
		path->north_texture = ft_strjoin(get_str(path->north_texture, s), str);
	}
	else
	{
		s = len(path->south_texture, '\\');
		path->south_texture = ft_strjoin(get_str(path->south_texture, s), str);
	}
}

int	check_path_of_texture(t_path *path, char *line, int a)
{
	if (path->north_texture == NULL || path->south_texture == NULL
		|| path->east_texture == NULL || path->west_texture == NULL
		|| path->floor_color == NULL || path->ceilling_color == NULL)
	{
		write(2, "error\n", 7);
		exit(0);
	}
	path->map_y = path->map_y - a;
	path->map[0] = ft_strdup(line);
	return (1);
}
