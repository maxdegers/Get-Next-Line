/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:01:45 by mbrousse          #+#    #+#             */
/*   Updated: 2023/12/04 21:04:04 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(int fd, char *rest)
{
	ssize_t	r;
	char	buff_read[BUFFER_SIZE];

	r = 1;
	while (r > 0)
	{
		r = read(fd, buff_read, BUFFER_SIZE);
		if (r == -1)
			return (NULL);
		buff_read[r] = '\0';
		rest = ft_strjoin_f(rest, buff_read);
		if (ft_strchr(rest, '\n') > 0)
			return (rest);
	}
	return (rest);
}

char	*ft_line(char *buffer)
{
	size_t	i;
	size_t	j;
	char	*line;

	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	line = malloc(sizeof(char) * i + 1);
	while (j < i)
	{
		line[j] = buffer[j];
		i++;
	}
	return (line);
}

char	*ft_next(char *line, char *str, char *buffer)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(line) + 1;
	j = 0;
	while (str[i])
	{
		buffer[j] = str[i];
		i++;
		j++;
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	size_t		i;
	static char	buffer[BUFFER_SIZE];
	char		*line;
	char		*rest;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	rest = malloc(sizeof(char) * ft_strlen(buffer) + 1);
	if (!rest)
		return (NULL);
	i = -1;
	while (buffer[++i])
		rest[i] = buffer[i];
	rest[i] = '\0';
	rest = read_file(fd, rest);
	if (!rest)
		return (NULL);
	line = ft_line(buffer);
	ft_next(line, rest, buffer);
	return (line);
}

#include <stdio.h> //TODO - remove
int main()
{
	int fd = open("test.txt", 0);
	char *line;
	
	if (fd < 0) {
		perror("Error opening file");
		return (0);
	}
	while ((line = get_next_line(fd)) != NULL) 
	{
		printf("Line read: %s\n", line);
		free(line);
	}
	close(fd);
	return 0;
}
