/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_range.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:38:36 by otmallah          #+#    #+#             */
/*   Updated: 2022/11/18 18:46:10 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	line_toint(char *str)
{
	int	j;

	j = 0;
	while (str[j])
	{
		if (str[j] >= '0' && str[j] <= '9')
			j++;
		else
		{
			write(2, "Wrong number\n", 13);
			exit(0);
		}
	}
}

void	utils_check_range(char **tab, t_path *path, int a)
{
	int		i;
	char	*str;

	i = 0;
	while (tab[i])
	{
		str = ft_strtrim(tab[i], " ");
		if (ft_strlen(str) > 3 || str[0] == '\t')
		{
			free(str);
			str = ft_strtrim(tab[i], "\t");
		}
		line_toint(str);
		if (!(ft_atoi(str) >= 0 && ft_atoi(str) <= 255))
		{
			write(2, "Out of range\n", 13);
			exit(0);
		}
		if (a == 0)
			path->color_of_f[i] = ft_atoi(str);
		else
			path->color_of_c[i] = ft_atoi(str);
		i++;
		free(str);
	}
}

void	check_multiplication_of_semicolon(char *line)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == ',')
			j++;
		i++;
	}
	if (j < 1 || j > 2)
	{
		write(2, "there is something wrong in F OR C, please try again!\n", 55);
		exit(0);
	}
}

int	range(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		while (tab[i][j] == 32 || tab[i][j] == '\t')
			j++;
		if (j > 0 && tab[i][j] == '\0')
		{
			write(2, "there is something wrong in F OR C\n", 36);
			exit(0);
		}
		j = 0;
		i++;
	}
	return (i);
}

void	check_range(char *line, t_path *path)
{
	int		i;
	int		a;
	char	*str;
	char	**tab;

	i = 0;
	a = 0;
	if (line[0] == 'C')
		a = 1;
	check_multiplication_of_semicolon(line);
	str = ft_strchr(line, ' ');
	if (!str)
		str = ft_strchr(line, '\t');
	tab = ft_split(str, ',');
	i = range(tab);
	if (i > 3 || i < 3 || !tab[1])
	{
		printf("just 3 numbers hh\n");
		exit(0);
	}
	utils_check_range(tab, path, a);
	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}
