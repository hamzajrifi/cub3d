/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_in_win.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 01:08:20 by hjrifi            #+#    #+#             */
/*   Updated: 2022/11/21 02:57:26 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x
			* (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	print_line_fov_2d(t_allData *all, t_rays ray)
{
	int	i;

	i = 0;
	ray = all->rays;
	ray.dx = all->rays.x1 - all->player.x;
	ray.dy = all->rays.y1 - all->player.y;
	ray.steps = calcul_steps(ray.dx, ray.dy);
	ray.xinc = ray.dx / (float)(ray.steps);
	ray.yinc = ray.dy / (float)(ray.steps);
	ray.x_p = all->player.x;
	ray.y_p = all->player.y;
	while (i <= ray.steps)
	{
		if (all->rays.found_h)
			my_mlx_pixel_put(&all->data, round(ray.x_p),
				round(ray.y_p), 0x0000FF);
		else
			my_mlx_pixel_put(&all->data, round(ray.x_p),
				round(ray.y_p), 0xbb00FF);
		ray.x_p += ray.xinc;
		ray.y_p += ray.yinc;
		i++;
	}
}

void	put_floor_and_ceilling(t_allData *all)
{
	int	i;
	int	j;
	int	color;

	color = all->path->color_c;
	j = 0;
	while (j < WIN_HEIGHT)
	{
		i = 0;
		if (j == WIN_HEIGHT / 2)
			color = all->path->color_f;
		while (i < WIN_WIDTH)
		{
			my_mlx_pixel_put(&all->data, i, j, color);
			i++;
		}
		j++;
	}
}

void	print_dda_lines(t_allData *all)
{
	int	j;

	j = 0;
	while (j < WIN_WIDTH)
	{
		check_rays(all);
		put_wall(all, j);
		all->ray_angle += (PI / 3) / WIN_WIDTH;
		j++;
	}
}
