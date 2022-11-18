/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_in_win.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 01:08:20 by hjrifi            #+#    #+#             */
/*   Updated: 2022/11/17 02:55:29 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	print_line_fov(t_allData *all, t_rays ray)
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
			my_mlx_pixel_put(&all->m_map, round(ray.x_p),
				round(ray.y_p), 0x0000FF);
		else
			my_mlx_pixel_put(&all->m_map, round(ray.x_p),
				round(ray.y_p), 0xbb00FF);
		ray.x_p += ray.xinc;
		ray.y_p += ray.yinc;
		i++;
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
