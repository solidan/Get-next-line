/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuesta- <acuesta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 10:37:12 by acuesta-          #+#    #+#             */
/*   Updated: 2023/03/06 12:22:58 by acuesta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include "get_next_line.h"

int	salto(char *line)
{
	int	i;

	i = 0;
	if (line == NULL)
		return (0);
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_read(int fd)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	bytes_read = read (fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0)
		return (NULL);
	if (bytes_read == 0)
	{
		free (buffer);
		return (NULL);
	}
	buffer[bytes_read] = '\0';
	return (buffer);
}

char	*ft_string(char *save, int fd)
{
	char	*string;
	char	*temp;
	char	*lib;

	string = save;
	while (!salto(string))
	{
		temp = ft_read(fd);
		if (temp == NULL)
			return (string);
		if (temp[0] == '\0')
		{
			free (temp);
			return (string);
		}
		lib = ft_strjoin (string, temp);
		free (string);
		free (temp);
		string = lib;
	}
	return (string);
}

int	ft_saltlin(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (save != NULL)
		{
			free(save);
			save = NULL;
		}
		return (NULL);
	}
	line = read_line(fd, &save); //? seria &save para que apuntara a una nueva ubicacion de la memoria
	if (!line)
		free(save);
	return (line);
}
