/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:01:47 by mbrousse          #+#    #+#             */
/*   Updated: 2023/12/04 10:45:09 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_join(int *j, char const *str, char *des)
{
	int	i;

	i = 0;
	while (str[i])
	{
		des[*j] = str[i];
		*j += 1;
		i++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tab;
	int		i;
	int		len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_sizetot(s1, s2);
	tab = malloc(sizeof(char) * len + 1);
	if (!tab)
		return (tab);
	i = 0;
	ft_join(&i, s1, tab);
	ft_join(&i, s2, tab);
	tab[i] = '\0';
	return (tab);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((unsigned char)c == s[i])
			return (&((char *)s)[i]);
		i++;
	}
	if ((unsigned char)c == 0)
	{
		return (((char *)s) + i);
	}
	return (0);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	i;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	if (size == 0)
		return (ptr);
	i = 0;
	while (i < nmemb * size)
	{
		((char *)ptr)[i] = '\0';
		i++;
	}
	return (ptr);
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
