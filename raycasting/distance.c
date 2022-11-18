/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 00:45:25 by hjrifi            #+#    #+#             */
/*   Updated: 2022/11/17 02:38:53 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

float	calcul_distance(t_player *player, float x1, float y1)
{
	float	dis;

	dis = sqrt((x1 - player->x) * (x1 - player->x) + (y1 - player->y)
			* (y1 - player->y));
	return (dis);
}

int	calcul_steps(int dx, int dy)
{
	int	steps;

	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	return (steps);
}

int	check_if_has_wall(t_allData *all, float x, float y)
{
	int	map_x;
	int	map_y;

	map_x = floor(x / TILE_SIZE);
	map_y = floor(y / TILE_SIZE);
	if (map_y < 0 || map_y >= all->path->map_y
		|| ft_strlen(all->path->map[map_y]) < (size_t)map_x)
		return (0);
	if (all->path->map[map_y][map_x] == '1')
		return (1);
	return (all->path->map[map_y][map_x] != '0');
}

void	check_distance_to_wall(t_allData *all)
{
	float	hir;
	float	ver;

	hir = calcul_distance(&all->player, all->rays.h_x, all->rays.h_y);
	ver = calcul_distance(&all->player, all->rays.v_x, all->rays.v_y);
	if (hir < ver)
	{
		all->rays.x1 = all->rays.h_x;
		all->rays.y1 = all->rays.h_y;
		all->rays.distance = hir;
		all->rays.found_h = 1;
		all->rays.found_v = 0;
	}
	else
	{
		all->rays.x1 = all->rays.v_x;
		all->rays.y1 = all->rays.v_y;
		all->rays.distance = ver;
		all->rays.found_h = 0;
		all->rays.found_v = 1;
	}
}
