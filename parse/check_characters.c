/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_characters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:34:15 by otmallah          #+#    #+#             */
/*   Updated: 2022/11/18 18:47:07 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	initial_char(t_cher *characters)
{
	characters->s_txtr = 0;
	characters->n_txtr = 0;
	characters->w_txtr = 0;
	characters->e_txtr = 0;
}

void	utils_check_line(char c, t_cher *characters)
{
	if (c == 'S')
		characters->s_txtr++;
	else if (c == 'E')
		characters->e_txtr++;
	else if (c == 'W')
		characters->w_txtr++;
	else if (c == 'N')
		characters->n_txtr++;
	else if (c != '0' && c != '1'
		&& (c != ' ' && c != '\t'))
	{
		write(2, "only 6 characyers\n", 19);
		exit(0);
	}
}

void	check_line(char *line, t_cher *characters, t_path *path)
{
	int	i;

	i = 0;
	while (line[i])
	{
		utils_check_line(line[i], characters);
		if (line[i] == 'S' || line[i] == 'E'
			|| line[i] == 'W' || line[i] == 'N')
		{
			path->pdirec = line[i];
			line[i] = '0';
		}
		i++;
	}
}

void	check_characters(t_path *path)
{
	t_cher	characters;
	int		i;

	i = 0;
	initial_char(&characters);
	while (path->map[i])
	{
		check_line(path->map[i], &characters, path);
		i++;
	}
	if (characters.s_txtr + characters.e_txtr + characters.w_txtr
		+ characters.n_txtr != 1)
	{
		write(2, "haja waheda hh\n", 16);
		exit(0);
	}
}

int	utiils_check_walls(t_path *path, int i, int j)
{
	while (path->map[i + 1])
	{
		while (path->map[i][j])
		{
			if (path->map[i][j] == 'N' || path->map[i][j] == 'S'
				|| path->map[i][j] == 'E' || path->map[i][j] == 'W')
			{
				path->pos_x_player = i;
				path->pos_y_player = j;
			}
			if (path->map[i][j] == '0' || path->map[i][j] == 'N'
				|| path->map[i][j] == 'E' || path->map[i][j] == 'W'
				|| path->map[i][j] == 'S')
			{
				if (check_position(path, i, j) == 1)
					j++;
			}
			else
				j++;
		}
		j = 0;
		i++;
	}
	return (i);
}
