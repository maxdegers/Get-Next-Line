/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:01:45 by mbrousse          #+#    #+#             */
/*   Updated: 2023/12/04 10:45:27 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

read_file

ft_line

ft_next

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0,0) <0)
		return (NULL);
	buffer = read_file
}

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
