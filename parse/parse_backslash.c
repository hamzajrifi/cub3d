/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_backslash.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:23:25 by otmallah          #+#    #+#             */
/*   Updated: 2022/11/18 18:47:31 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	check_position(t_path *path, int i, int j)
{
	if (j >= (int)ft_strlen(path->map[i - 1])
		|| j >= (int)ft_strlen(path->map[i + 1]))
	{
		write(2, "error\n", 7);
		exit(0);
	}
	if (((path->map[i - 1][j] != ' ' && path->map[i - 1][j] != '\t')
		&& (path->map[i + 1][j] != ' ' && path->map[i + 1][j] != '\t'))
		&& (j != 0 && (path->map[i][j - 1] != ' '
		&& path->map[i][j - 1] != '\t')
		&& (path->map[i][j + 1] != ' ' && path->map[i][j + 1] != '\t')))
		return (1);
	else
	{
		write(2, "error\n", 7);
		exit(0);
	}
	return (0);
}

void	check_walls(t_path *path)
{
	int	i;
	int	j;

	first_line(path);
	i = 1;
	j = 0;
	i = utiils_check_walls(path, i, j);
	last_line(path, i);
}

void	check_duplicate(t_path *path)
{
	int	k;

	k = 0;
	while (k < 6)
	{
		if (path->tab[k] != 1)
		{
			printf("there is something wroooooong in map\n");
			exit(0);
		}
		k++;
	}
}

void	check_backslash(t_check_map *check, t_path *path, int j)
{
	int	i;

	i = 0;
	check->i_i = 0;
	check->size = ft_strlen(check->str);
	while (check->str[i])
	{
		if (check->str[i] == '\\' && check->str[i + 1])
			i += 2;
		else
			i++;
		check->i_i++;
	}
	check->tab1 = malloc(sizeof(char) * (check->i_i + 1));
	i = 0;
	while (check->str[i])
	{
		if (check->str[i] == '\\' && check->str[i + 1])
			i++;
		if (check->str[i])
			check->tab1[j++] = check->str[i++];
	}
	check->tab1[j] = '\0';
	add_valid_path(path, check->i, check->tab1);
	free(check->tab1);
}

void	check_path_xpm(t_path *path)
{
	t_check_map	check;

	check.tab = (char **)malloc(sizeof(char *) * 4);
	check.tab[0] = path->east_texture;
	check.tab[1] = path->west_texture;
	check.tab[2] = path->north_texture;
	check.tab[3] = path->south_texture;
	check.i = -1;
	while (++check.i < 4)
	{
		check.str = ft_strchr(check.tab[check.i], '\\');
		if (check.str)
			check_backslash(&check, path, 0);
		else if (ft_strchr(check.tab[check.i], ' '))
		{
			write(2, "error path\n", 12);
			exit(0);
		}
	}
	free(check.tab);
}
