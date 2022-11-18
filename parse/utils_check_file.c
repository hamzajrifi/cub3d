/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 03:07:53 by otmallah          #+#    #+#             */
/*   Updated: 2022/11/18 18:44:10 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	get_no(char *str, t_path *path)
{
	int	i;

	i = 2;
	while (*(str + i) == ' ' || *(str + i) == '\t')
		i++;
	path->tab[0] += 1;
	path->north_texture = ft_strdup(str + i);
}

void	get_so(char *str, t_path *path)
{
	int	i;

	i = 2;
	while (*(str + i) == ' ' || *(str + i) == '\t')
		i++;
	path->tab[1] += 1;
	path->south_texture = ft_strdup(str + i);
}

void	get_we(char *str, t_path *path)
{
	int	i;

	i = 2;
	path->tab[2] += 1;
	while (*(str + i) == ' ' || *(str + i) == '\t')
		i++;
	path->west_texture = ft_strdup(str + i);
}

void	get_ea(char *str, t_path *path)
{
	int	i;

	i = 2;
	path->tab[3] += 1;
	while (*(str + i) == ' ' || *(str + i) == '\t')
		i++;
	path->east_texture = ft_strdup(str + i);
}

void	get_f(char *str, t_path *path)
{
	path->tab[4] += 1;
	check_range(str, path);
	path->floor_color = ft_strdup(str);
}
