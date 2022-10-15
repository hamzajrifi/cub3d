/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 19:10:53 by hjrifi            #+#    #+#             */
/*   Updated: 2022/04/10 00:42:37 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_strchr(char *s, int c)
{
	int		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (&s[i + 1]);
		i++;
	}
	if (c == '\0')
		return (&s[i]);
	return (NULL);
}

void	free_mytab(char	**str)
{
	free(*str);
	*str = NULL;
}

char	*my_newline(char **rest_line)
{
	char	*tmp;
	char	*line;
	int		i;

	i = 0;
	if (!*rest_line || !(*rest_line)[0])
	{
		free_mytab(rest_line);
		return (NULL);
	}
	while ((*rest_line)[i] && (*rest_line)[i] != '\n')
		i++;
	if ((*rest_line)[i] == '\n')
	{
		line = ft_substr(*rest_line, 0, ++i);
		tmp = ft_strdup(*rest_line + i);
		free_mytab(rest_line);
		*rest_line = tmp;
		return (line);
	}
	line = ft_strdup(*rest_line);
	free_mytab(rest_line);
	return (line);
}

char	*ft_check(char **rest_line, char **line)
{
	free_mytab(rest_line);
	free_mytab(line);
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*rest_line;
	int			size_line;

	size_line = 1;
	line = malloc(sizeof(char) * 10 + 1);
	if (!line)
		return (NULL);
	if (fd < 0 || 10 <= 0)
	{
		free_mytab(&line);
		return (NULL);
	}
	if (!rest_line)
		rest_line = ft_strdup("");
	while (size_line > 0 && !ft_strchr(rest_line, '\n'))
	{
		size_line = read (fd, line, 10);
		if (size_line < 0)
			return (ft_check(&rest_line, &line));
		line[size_line] = '\0';
		rest_line = ft_strjoin(rest_line, line);
	}
	free_mytab(&line);
	return (my_newline(&rest_line));
}
