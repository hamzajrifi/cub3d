/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rander_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 01:20:03 by hjrifi            #+#    #+#             */
/*   Updated: 2022/11/19 00:22:47 by hjrifi           ###   ########.fr       */
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

void	update_player(t_allData *all)
{
	float	move_step;
	float	new_px;
	float	new_py;
	float	p = 0;

	all->player.rotation_angle += all->player.turn_d * all->player.turnspeed;
	all->ray_angle = all->player.rotation_angle - (PI / 6);
	move_step = all->player.walk_d * all->player.walkspeed;
	if (all->player.walk_lr)
	{
		move_step = all->player.walk_lr * all->player.walkspeed;
		p = PI / 2;
	}
	new_px = all->player.x + cos(all->player.rotation_angle + p) * move_step ;
	new_py = all->player.y + sin(all->player.rotation_angle + p) * move_step ;
	
	if (!check_if_has_wall(all, new_px, new_py))
	{
		all->player.x = new_px;
		all->player.y = new_py;
	}
}

void	raycasting(t_allData *all)
{
	mlx_destroy_image(all->i_win.mlx, all->data.img);
	initial_win_data(all);
	put_floor_and_ceilling(all);
	mini_map(all);
	print_dda_lines(all);
	mlx_put_image_to_window(all->i_win.mlx, all->i_win.mlx_win,
		all->data.img, 0, 0);
	mlx_put_image_to_window(all->i_win.mlx, all->i_win.mlx_win,
		all->m_map.img, 1008, 708);
}
