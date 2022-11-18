/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 00:46:42 by hjrifi            #+#    #+#             */
/*   Updated: 2022/11/17 15:44:10 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	check_horizontal_next_wall(t_allData *all)
{
	float	tmpy;

	tmpy = all->rays.h_y;
	while (all->rays.h_x >= 0 && all->rays.h_y >= 0 && all->rays.h_x
		<= all->path->map_x * TILE_SIZE && all->rays.h_y
		<= all->path->map_y * TILE_SIZE)
	{
		if (all->ray_angle > PI && all->ray_angle < 2 * PI)
			tmpy = all->rays.h_y - 1;
		else
			tmpy = all->rays.h_y;
		if (check_if_has_wall(all, all->rays.h_x, tmpy))
		{
			all->rays.found_h = 1;
			break ;
		}
		else
		{
			all->rays.h_x += all->rays.xinc;
			all->rays.h_y += all->rays.yinc;
		}
	}
}

void	find_horizontal(t_allData *all)
{
	if (all->ray_angle < PI && all->ray_angle > 0)
	{
		all->rays.h_y = floor(all->player.y / TILE_SIZE) * TILE_SIZE
			+ TILE_SIZE;
		all->rays.yinc = TILE_SIZE;
	}
	else
	{
		all->rays.h_y = floor(all->player.y / TILE_SIZE) * TILE_SIZE;
		all->rays.yinc = -TILE_SIZE;
	}
	all->rays.h_x = all->player.x + (all->rays.h_y - all->player.y)
		/ tan(all->ray_angle);
	all->rays.xinc = TILE_SIZE / tan(all->ray_angle);
	if (all->rays.xinc > 0 && all->ray_angle > PI / 2 && all->ray_angle
		< 3 * PI / 2)
		all->rays.xinc = -all->rays.xinc;
	if (all->rays.xinc < 0 && (all->ray_angle < PI / 2 || all->ray_angle
			> 3 * PI / 2))
		all->rays.xinc = -all->rays.xinc;
	check_horizontal_next_wall(all);
}

void	check_vertical_next_wall(t_allData *all)
{
	float	tmpx;

	tmpx = all->rays.v_x;
	while (all->rays.v_y >= 0 && all->rays.v_x >= 0 && all->rays.v_x
		<= all->path->map_x * TILE_SIZE && all->rays.v_y <= all->path->map_y
		* TILE_SIZE)
	{
		if (all->ray_angle > PI / 2 && all->ray_angle < 3 * PI / 2)
			tmpx = all->rays.v_x - 1;
		else
			tmpx = all->rays.v_x;
		if (check_if_has_wall(all, tmpx, all->rays.v_y))
		{
			all->rays.found_v = 1;
			break ;
		}
		else
		{
			all->rays.v_x += all->rays.xinc;
			all->rays.v_y += all->rays.yinc;
		}
	}
}

void	find_vertical(t_allData *all)
{
	if (all->ray_angle < PI / 2 || all->ray_angle > 3 * PI / 2)
	{
		all->rays.v_x = floor(all->player.x / TILE_SIZE) * TILE_SIZE
			+ TILE_SIZE;
		all->rays.xinc = TILE_SIZE;
	}
	else
	{
		all->rays.v_x = floor(all->player.x / TILE_SIZE) * TILE_SIZE;
		all->rays.xinc = -TILE_SIZE;
	}
	all->rays.v_y = all->player.y + (all->rays.v_x - all->player.x)
		* tan(all->ray_angle);
	all->rays.yinc = TILE_SIZE * tan(all->ray_angle);
	if (all->ray_angle > PI && all->rays.yinc > 0)
		all->rays.yinc = -all->rays.yinc;
	if (all->ray_angle < PI && all->rays.yinc < 0)
		all->rays.yinc = -all->rays.yinc;
	check_vertical_next_wall(all);
}

void	check_rays(t_allData *all)
{
	all->ray_angle = remainder(all->ray_angle, 2 * PI);
	if (all->ray_angle < 0)
			all->ray_angle += 2 * PI;
	all->rays.found_h = 0;
	all->rays.found_v = 0;
	find_horizontal(all);
	if (all->rays.found_h == 0)
		all->rays.h_x = 2000000;
	find_vertical(all);
	if (all->rays.found_v == 0)
		all->rays.v_y = 2000000;
	check_distance_to_wall(all);
}
