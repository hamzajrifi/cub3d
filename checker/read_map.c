#include "../cub3d.h"

static int check_path_map(char *path_map)
{
    int i;
    int len;
    char *tab;
    int tmp_len;

    tab = ft_strdup("buc.");
    i = 0;
    len = ft_strlen(path_map);
    tmp_len = len;
    while (tmp_len > 4 && tab[i] == path_map[len - i - 1])
    {
        i++;
    }
    free(tab);
    if (i != 4)
    {
        printf("map is not format .cub\n");
        return (1);
    }
    return (0);
}

int skip_speace(char *str, char *dst)
{
    int     i;
    int     j;
    int     len;

    i = 0;
    j = 0;
    while (str && (str[i] == ' ' || str[i] == '\r' || str[i] == '\t'))
        i++;
    if (!str || !str[i])
        return (1);
    len = ft_strlen(&str[i]) + i;
    free(dst);
    dst = malloc (sizeof(char *) * len);
    while (len > i && str[i] != ' ' && str[i] != '\t' && str[i] != '\r' && str[i] != '\n')
    {
        dst[j] = str[i];
        i++;
        j++;
    }
    dst[j] = '\0';
    while (str && (str[i] == ' ' || str[i] == '\r' || str[i] == '\t'))
        i++;
    if (str[i] && str[i] != '\n')
        return (1);
    return (0);
}

char    *skip_new_line_and_speaces(t_data *data)
{
    int     i;
    char    *str;

    i = 0;
    str = get_next_line(data->fd);
    if (!str)
        return (NULL);
    while (str && (str[i] == ' ' || str[i] == '\r' || str[i] == '\t' || str[i] == '\n'))
    {
        i++;
        if (!str[i])
        {
            i = 0;
            free(str);
            str = get_next_line(data->fd);
        }
    }
    return (&str[i]);
}

int check_north(t_data *data)
{
    char    *str;
    int     i;

// ========  check north
    str = skip_new_line_and_speaces(data);
    i = 0;
    if (!str)
        return (ft_error("File map is umpty"));
    while (str && data->north.NO[i] == str[i])
        i++;
    if ((str[i] != ' ' && str[i] != '\t' && str[i] != '\r')|| skip_speace(&str[i], data->north.NO) || i != 2)
        return (ft_error("NO is Wrong"));
// ========  check south
    str = skip_new_line_and_speaces(data);
    i = 0;
    while (str && data->north.SO[i] == str[i])
        i++;
    if (!str || (str[i] != ' ' && str[i] != '\t' && str[i] != '\r')|| skip_speace(&str[i], data->north.SO) || i != 2)
        return (ft_error("SO is Wrong"));
// ========  check West
    str = skip_new_line_and_speaces(data);
    i = 0;
    while (str && data->north.WE[i] == str[i])
        i++;
    if (!str || (str[i] != ' ' && str[i] != '\t' && str[i] != '\r')|| skip_speace(&str[i], data->north.WE) || i != 2)
        return (ft_error("WE is Wrong"));
// ========  check East
    str = skip_new_line_and_speaces(data);
    i = 0;
    while (str && data->north.EA[i] == str[i])
        i++;
    if (!str || (str[i] != ' ' && str[i] != '\t' && str[i] != '\r')|| skip_speace(&str[i], data->north.EA) || i != 2)
        return (ft_error("EA is Wrong"));
// ========  Floor color


// ========  Ceilling color
    
    return (0);
}

int read_map(t_data *data)
{
    if (check_path_map(data->path_map))
        return (1);
    data->fd = open(data->path_map, O_RDWR, 0677);
    data->north.NO = ft_strdup("NO");
    data->north.SO = ft_strdup("SO");
    data->north.WE = ft_strdup("WE");
    data->north.EA = ft_strdup("EA");
    if (data->fd < 0 || check_north(data))
        return (1);

    return (0);
}