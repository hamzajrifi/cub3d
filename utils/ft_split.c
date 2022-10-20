/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 12:41:13 by hjrifi            #+#    #+#             */
/*   Updated: 2021/11/20 16:02:33 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	ft_ntab(char const *s, char c)
{
	int	ntab;
	int	i;

	i = 0;
	ntab = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			ntab++;
			i--;
		}
		i++;
	}
	return (ntab);
}

static char	**ft_copy(char **tab, char const *s, int ntab, int c)
{
	int	b;
	int	a;
	int	i;

	i = 0;
	a = 0;
	while (a < ntab)
	{
		while (s[i] && s[i] == c)
			i++;
		b = i;
		while (s[i] != c && s[i])
			i++;
		tab[a] = ft_libft_substr(s, b, (i - b));
		if (!*tab)
		{
			while (a > 0)
				free(tab[a--]);
			free (tab);
			return (NULL);
		}
		a++;
	}
	tab[a] = (NULL);
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	int		ntab;
	char	**tab;

	if (!s)
		return (NULL);
	ntab = ft_ntab(s, c);
	tab = (char **)malloc(sizeof(char *) * (ntab + 1));
	if (!tab)
		return (NULL);
	ft_copy (tab, s, ntab, c);
	return (tab);
}