/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuesta- <acuesta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 10:22:43 by acuesta-          #+#    #+#             */
/*   Updated: 2023/02/01 12:33:16 by acuesta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"


int	salto(char	*line)//? busca salto de linea. si es verdadero entonces devuelve 1 y si es false devuelve 0 
{
	int i;

	i = 0;
	if(line == NULL)
		return(0);
	while(line[i] != '\0')//? itera toda la string
	{
		if(line[i] == '\n')//? si encuentra salto de linea devuelve 1
			return(1);
		i++;
	}
	return(0); //? despues de iterar la string y no encuentra salto de linea devuelve 0
}

char	*ft_read(int fd)//? lee y devuelve string
{
	char	*buffer;
	int		bytes_read;


	buffer = malloc(BUFFER_SIZE + 1);
	//printf("[%p]\n", buffer);
	if(!buffer)
		return(NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == -1)
	{
		free(buffer);
		return(NULL);
	}
	buffer[bytes_read] = '\0';
	printf("%s\n", buffer);
	return(buffer);
}


char	*ft_line(char	*s, int fd) //? se usa para detectar la primera linea de texto de una cadena de caracteres
{
	char	*line;
	int		i;
	
	i = 0;
	line = NULL;
	while(!salto(line)) //? es verdadero cuando no ahi salto de linea en line 
	{
		//line = ft_read(fd);//? guarda el contenido de ft_read en line y no tiene que ser una linea completa
		line = ft_strjoin(line, ft_read(fd));
	}
	
	if (line == NULL)
	{
		return (NULL);
	}
	return(line);
}

//? guardar los caracteres usando strjoin



char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if(fd < 0 || BUFFER_SIZE<= 0)
		return(0);
	if(!save)
		return(NULL);
	line = ft_line(save, fd);//?devuelme una linea o mas
	save = ;//? guardar sobras
	line = ;//?una linea completa o hasta EOF (end of file)
	if (line == NULL)
		return(NULL);
	return (line);
}

/*
orden
encontrar salto de linea 
cortar la string donde este el salto de linea 
*/
















// char	*get_next_line(int fd)
// {
// 	char		*line;
// 	static char	*save;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (0);
// 	save = ft_read_and_save(fd, save);
// 	if (!save)
// 		return (NULL);
// 	line = ft_get_line(save);
// 	save = ft_save(save);
// 	return (line);
// }