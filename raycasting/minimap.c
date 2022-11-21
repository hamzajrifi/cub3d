/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 02:27:29 by hjrifi            #+#    #+#             */
/*   Updated: 2022/11/20 21:16:25 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	rec(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;
	int	a;
	int	b;

	b = y;
	i = -1;
	while (++i < (TILE_SIZE / 4))
	{
		j = -1;
		a = x;
		while (++j < (TILE_SIZE / 4))
		{
			my_mlx_pixel_put(data, a, b, color);
			a++;
		}
		b++;
	}
}

void	print_directions(t_allData *all, t_rays ray)
{
	int	i;

	i = 0;
	ray.dx = (72 + cos(all->player.rotation_angle) * 20) - 72;
	ray.dy = (72 + sin(all->player.rotation_angle) * 20) - 72;
	ray.steps = calcul_steps(ray.dx, ray.dy);
	ray.xinc = ray.dx / (float)(ray.steps);
	ray.yinc = ray.dy / (float)(ray.steps);
	ray.x_p = 72;
	ray.y_p = 72;
	while (i <= ray.steps)
	{
		if (all->rays.found_h)
			my_mlx_pixel_put(&all->m_map, round(ray.x_p),
				round(ray.y_p), 0xFFFFFF);
		else
			my_mlx_pixel_put(&all->m_map, round(ray.x_p),
				round(ray.y_p), 0xbb00FF);
		ray.x_p += ray.xinc;
		ray.y_p += ray.yinc;
		i++;
	}
}

int	check_player(t_allData *all, int x_r, int y_r)
{
	int	x;
	int	y;

	x_r = x_r - 5;
	y_r = y_r - 5;
	x = (all->player.x / TILE_SIZE) - x_r;
	y = (all->player.y / TILE_SIZE) - y_r;
	if (x < 0 || y < 0 || y >= all->path->map_y || x
		>= (int)ft_strlen(all->path->map[y]))
		return (0);
	if (all->path->map[y][x] == '0')
		return (1);
	return (0);
}

void	player(t_data *data)
{
	int	i;
	int	j;
	int	y;
	int	k;

	j = 0;
	k = 65;
	y = 65;
	while (j < 14)
	{
		i = 0;
		while (i < 14)
		{
			my_mlx_pixel_put(data, k, y, 0xFF0000);
			k++;
			i++;
		}
		k = 65 ;
		y++;
		j++;
	}
}

void	mini_map(t_allData *all)
{
	int	x;
	int	y;

	y = 0;
	while (y < 10)
	{
		x = 0;
		while (x < 10)
		{
			if (check_player(all, x, y))
				rec(&all->m_map, (9 - x) * TILE_SIZE / 4, (9 - y)
					* TILE_SIZE / 4, 0xA6a0a6);
			else
				rec(&all->m_map, (9 - x) * TILE_SIZE / 4, (9 - y)
					* TILE_SIZE / 4, 0xae2c5d);
			x++;
		}
		y++;
	}
	player(&all->m_map);
	print_directions(all, all->rays);
}
