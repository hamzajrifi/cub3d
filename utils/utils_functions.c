#include "../cub3d.h"

int calc_line(char **map)
{
    int i;
    (void) **map;
    i = 0;
    return (i);
}

static long	ft_skip(char *str)
{
	long	i;

	i = 0;
	while (str[i] == '\n' || str[i] == '\r' || str[i] == ' '
		|| str[i] == '\t' || str[i] == '\v' || str[i] == '\f')
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	long	i;
	long	signe;
	long	rest;

	i = 0;
	signe = 1;
	rest = 0;
	i = ft_skip((char *)str);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		rest = rest * 10 + (str[i] - 48);
		if (rest < -2147483648 && signe == -1)
			return (0);
		if (rest > 2147483647 && signe == 1)
			return (-1);
		i++;
	}
	return (rest * signe);
}

