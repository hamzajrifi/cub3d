/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 03:01:03 by hjrifi            #+#    #+#             */
/*   Updated: 2022/11/18 16:12:48 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	get_color(t_texture txtr_n, int x, float y, float s_wall)
{
	int		txtr_x;
	int		txtr_y;
	char	*dst;

	txtr_x = x % 64;
	txtr_y = (int)(y * 64 / s_wall) % 64;
	dst = txtr_n.add + (txtr_y * txtr_n.sizeline + txtr_x
			* (txtr_n.pixle_b / 8));
	return (*(int *)dst);
}

void	put_img_to_wall(t_allData *all, t_wall wall, int x)
{
	int	i;
	int	color;

	i = 0;
	while (wall.top_y < wall.btm_y)
	{
		if (all->rays.found_h)
		{
			if (all->ray_angle > PI && all->ray_angle < 2 * PI)
				color = get_color(all->txtr_n, all->rays.x1, i, wall.wall_he);
			else
				color = get_color(all->txtr_s, all->rays.x1, i, wall.wall_he);
			my_mlx_pixel_put(&all->data, x, wall.top_y, color);
		}
		else
		{
			if (all->ray_angle > 3 * PI / 2 || all->ray_angle < PI / 2)
				color = get_color(all->txtr_w, all->rays.y1, i, wall.wall_he);
			else
				color = get_color(all->txtr_e, all->rays.y1, i, wall.wall_he);
			my_mlx_pixel_put(&all->data, x, wall.top_y, color);
		}
		wall.top_y++;
		i++;
	}
}

void	check_coordinates(t_allData *all, t_wall wall, int x, int i)
{
	int	color;

	if (all->rays.found_h)
	{
		if (all->ray_angle > PI && all->ray_angle < 2 * PI)
			color = get_color(all->txtr_n, all->rays.x1,
					wall.top_y, wall.wall_he);
		else
			color = get_color(all->txtr_s, all->rays.x1,
					wall.top_y, wall.wall_he);
		my_mlx_pixel_put(&all->data, x, i, color);
	}
	else
	{
		if (all->ray_angle > 3 * PI / 2 || all->ray_angle < PI / 2)
			color = get_color(all->txtr_w, all->rays.y1,
					wall.top_y, wall.wall_he);
		else
			color = get_color(all->txtr_e, all->rays.y1,
					wall.top_y, wall.wall_he);
		my_mlx_pixel_put(&all->data, x, i, color);
	}
}

void	print_txtr_img(t_allData *all, t_wall wall, int x)
{
	int	i;

	i = 0;
	if (wall.top_y <= 0)
	{
		wall.top_y = fabsf(wall.top_y);
		i = 0;
		while (i < WIN_HEIGHT)
		{
			check_coordinates(all, wall, x, i);
			wall.top_y++;
			i++;
		}
		return ;
	}
	put_img_to_wall(all, wall, x);
}

void	put_wall(t_allData *all, int x)
{
	t_wall	wall;

	wall.dg = all->player.rotation_angle - all->ray_angle;
	if (wall.dg < 0)
		wall.dg += 2 * M_PI;
	else if (wall.dg > 2 * M_PI)
		wall.dg -= 2 * M_PI;
	wall.wall_he = WIN_WIDTH / (all->rays.distance * cos(wall.dg)) * 64;
	wall.top_y = WIN_HEIGHT / 2 - wall.wall_he / 2;
	wall.btm_y = wall.top_y + wall.wall_he;
	print_txtr_img(all, wall, x);
}
