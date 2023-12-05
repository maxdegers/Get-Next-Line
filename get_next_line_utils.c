/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:01:47 by mbrousse          #+#    #+#             */
/*   Updated: 2023/12/04 20:52:51 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_f(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	size;
	char	*tab;

	size = 0;
	while (s2[size] != '\n' && s2[size] != 0)
		size++;
	if (s2[size] == '\n')
		size++;
	tab = malloc(sizeof(char) * (ft_strlen(s1) + size + 1));
	if (tab == NULL)
		return (free(s1), NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		tab[i] = s1[i];
		i++;
	}
	while (s2 && j++ < size)
		tab[i + j - 1] = s2[j - 1];
	tab[i + j - 1] = 0;
	free(s1);
	return (tab);
}

int	ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (ft_strlen(s + i) == 0)
		return (0);
	while (s[i])
	{
		if ((unsigned char)c == s[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strdup(char *s)
{
	size_t	i;
	size_t	size;
	char	*tab;

	size = 0;
	while (s[size] != '\n' && s[size] != 0)
		size++;
	if (s[size] == '\n')
		size++;
	tab = malloc(sizeof(char) * (size + 1));
	if (tab == NULL)
		return (tab);
	i = 0;
	while (i < size)
	{
		tab[i] = s[i];
		i++;
	}
	tab[i] = 0;
	return (tab);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
