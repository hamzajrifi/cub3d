/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_2d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 02:50:24 by hjrifi            #+#    #+#             */
/*   Updated: 2022/11/21 02:51:07 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static void	rec_2d(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;
	int	a;
	int	b;

	b = y;
	i = -1;
	while (++i < TILE_SIZE - 1)
	{
		j = -1;
		a = x;
		while (++j < TILE_SIZE - 1)
		{
			my_mlx_pixel_put(data, a, b, color);
			a++;
		}
		my_mlx_pixel_put(data, a, b, 0x9E9E9E9E);
		b++;
	}
	while (j < TILE_SIZE)
	{
		my_mlx_pixel_put(data, a, b, 0x9E9E9E9E);
		a++;
		j++;
	}
}

void	mini_map_2d(t_allData *all)
{
	int	x;
	int	y;

	y = 0;
	while (all->path->map[y])
	{
		x = 0;
		while (all->path->map[y][x])
		{
			if (all->path->map[y][x] == '1')
				rec_2d(&all->data, x * TILE_SIZE, y * TILE_SIZE, 0xFFFFFF);
			else if (all->path->map[y][x] == '0')
				rec_2d(&all->data, x * TILE_SIZE, y * TILE_SIZE, 0xFFE0B2);
			x++;
		}
		y++;
	}
}
