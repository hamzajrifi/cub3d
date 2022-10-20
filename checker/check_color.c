#include "../cub3d.h"

static char *ft_skip_space(char *str)
{
    int i;
    char *tmp;

    i = 0;
    if (!str)
        return (NULL);
    while (str && (str[i] == ' ' || str[i] == '\r' || str[i] == '\t'))
        i++;
	if (!str[i])
		return (NULL);
    tmp = ft_strdup(&str[i]);
    free(str);
    return (tmp);
}

void	utils_check_range(char **tab)
{
	int i = 0;
	int j = 0;
	char *str;

	while(tab[i])
	{
		str = ft_strtrim(tab[i], " ");
		while(str[j])
		{
			if (str[j] >= '0' && str[j] <= '9')
				j++;
			else if (str[j] != '\n')
			{
				write(2, "Wrong number\n", 13);
				exit(0);
			}
		}
		if (!(ft_atoi(str) >= 0 && ft_atoi(str) <= 255))
		{
			write(2, "Out of range\n", 13);
			exit(0);
		}
		j = 0;
		i++;
		free(str);
	}
}

int get_nbr_color(t_data *data, char *str)
{
    
	char **tab = ft_split(str, ',');
	int i;

	i = 0;
	while(tab[i])
	{
        i++;
	}
	if (i != 3 || ft_strlen(tab[0]) < 1 || (tab[0][1] != ' ' && tab[0][1] != '\t' && tab[0][1] != '\r'))
	{
		printf("color is wrong\n");
		return (-1);
	}
	utils_check_range(tab);
    puts("here");
    return (0);
}