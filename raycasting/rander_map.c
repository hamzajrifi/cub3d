/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rander_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 01:20:03 by hjrifi            #+#    #+#             */
/*   Updated: 2022/11/21 03:06:17 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	check_move_horizontal(t_allData *all, float dg)
{
	float	x;
	float	y;

	if (dg < PI && dg > 0)
		y = floor(all->player.y / 64) * 64 + 64;
	else
		y = floor(all->player.y / 64) * 64;
	x = all->player.x + (y - all->player.y) / tan(dg);
	if (dg > PI && dg < 2 * PI)
		y -= 1;
	if (check_if_has_wall(all, x, y) && calcul_distance
		(&all->player, x, y) < 4.0)
		return (1);
	return (0);
}

int	check_move_vertical(t_allData *all, float dg)
{
	float	x;
	float	y;

	if (dg < PI / 2 || dg > 3 * PI / 2)
		x = floor(all->player.x / 64) * 64 + 64;
	else
		x = floor(all->player.x / 64) * 64;
	y = all->player.y + (x - all->player.x) * tan(dg);
	if (dg > PI / 2 && dg < 3 * PI / 2)
		x -= 1;
	if (check_if_has_wall(all, x, y) && calcul_distance
		(&all->player, x, y) < 4.0)
		return (1);
	return (0);
}

int	check_player_move(t_allData *all)
{
	float	dg;

	dg = all->player.rotation_angle;
	if (all->player.walk_d == -1)
		dg += PI;
	dg = remainder(dg, 2 * PI);
	if (dg < 0)
			dg += 2 * PI;
	if (check_move_horizontal(all, dg) || check_move_vertical(all, dg))
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
	if (check_if_has_wall(all, new_px, new_py) || (all->player.walk_d
			&& check_player_move(all)))
		return ;
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
