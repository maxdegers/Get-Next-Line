/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:01:45 by mbrousse          #+#    #+#             */
/*   Updated: 2023/11/19 19:17:38 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFFER_SIZE

char	*get_next_line(int fd)
{
	static char	*static_str;
	char		*line;

	while
}

int	main(void) // a retirer
{
	int fd = open("test.txt", 0);
	char *line;

	if (fd < 0)
	{
		perror("Error opening file");
		return (0);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Line read: %s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}
