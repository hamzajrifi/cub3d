/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rander_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 01:20:03 by hjrifi            #+#    #+#             */
/*   Updated: 2022/11/21 02:25:56 by hjrifi           ###   ########.fr       */
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

int	check_player_move(t_allData *all, float x, float y)
{
	float dg;
	
	dg = all->player.rotation_angle;
	if (all->player.walk_d == -1)
		dg += PI;
	dg = remainder(dg, 2 * PI);
	if (dg < 0)
			dg += 2 * PI;
	if ( dg < PI && dg > 0)
		y = floor(all->player.y / 64) * 64 + 64;
	else
		y = floor(all->player.y / 64) * 64;
	x = all->player.x + (y - all->player.y) / tan(dg);
	if (dg > PI && dg < 2 * PI)
		y -= 1;
	if (check_if_has_wall(all, x, y) && calcul_distance(&all->player, x, y) < 4.0)
		return (1);
	if (dg < PI / 2 || dg > 3 * PI / 2)
		x = floor(all->player.x / 64) * 64 + 64;
	else
		x = floor(all->player.x / 64) * 64;
	y = all->player.y + (x - all->player.x) * tan(dg);
	if (dg > PI / 2 && dg < 3 * PI / 2)
		x -= 1;
	if (check_if_has_wall(all, x, y) && calcul_distance(&all->player, x, y) < 4.0)
		return (1);
	return (0);
}

void	update_player(t_allData *all)
{
	float	move_step;
	float	new_px;
	float	new_py;
	float	p;

	p = 0;
	all->player.rotation_angle += all->player.turn_d * all->player.turnspeed;
	all->ray_angle = all->player.rotation_angle - (PI / 6);
	move_step = all->player.walk_d * all->player.walkspeed;
	if (all->player.walk_lr)
	{
		move_step = all->player.walk_lr * all->player.walkspeed;
		p = PI / 2;
	}
	new_px = all->player.x + cos(all->player.rotation_angle + p) * move_step;
	new_py = all->player.y + sin(all->player.rotation_angle + p) * move_step;
	/// 
	float tmp_x = new_px;
	float tmp_y = new_py;
		
	if (check_if_has_wall(all, tmp_x, tmp_y) || (all->player.walk_d && check_player_move(all, tmp_x, tmp_y)))
		return ;
	if (!check_if_has_wall(all, tmp_x, tmp_y))
	{
		all->player.x = new_px;
		all->player.y = new_py;
	}
}

void	raycasting(t_allData *all)
{
	mlx_destroy_image(all->i_win.mlx, all->data.img);
	initial_win_data(all);
	//put_floor_and_ceilling(all);
	// mini_map_2d(all);
	mini_map(all);
	print_dda_lines(all);
	mlx_put_image_to_window(all->i_win.mlx, all->i_win.mlx_win,
		all->data.img, 0, 0);
	mlx_put_image_to_window(all->i_win.mlx, all->i_win.mlx_win,
		all->m_map.img, 1008, 708);
}
