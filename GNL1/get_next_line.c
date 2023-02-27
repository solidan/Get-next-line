/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuesta- <acuesta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 10:37:12 by acuesta-          #+#    #+#             */
/*   Updated: 2023/02/27 13:07:35 by acuesta-         ###   ########.fr       */
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
	{
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

	string = NULL;
	if (save)
		string = save;
	while (!salto(string))
	{
		temp = ft_read(fd);
		if (temp[0] == '\0')
		{
			free (temp);
			return (string);
		}
		if (temp == NULL)
			return (string);
		lib = ft_strjoin (string, temp);
		if (string == NULL)
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
	char		*line;
	static char	*save = NULL;
	int			i;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	line = ft_string (save, fd);
	if (line == NULL)
		return (NULL);
	i = ft_saltlin (line);
	if (line[i] == '\n')
	{
		save = ft_substr (line, i + 1, ft_strlen(line + i + 1));
		temp = ft_substr (line, 0, i + 1);
		free(line);
		line = temp;
	}
	else
		save = NULL;
	if (!line)
		return (NULL);
	return (line);
}
