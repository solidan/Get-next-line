/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuesta- <acuesta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 10:22:43 by acuesta-          #+#    #+#             */
/*   Updated: 2023/02/06 12:16:47 by acuesta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

 int	salto(char	*line)//? busca salto de linea. si es verdadero entonces devuelve 1 y si es false devuelve 0 
 {
 	int	i;

 	i = 0;
 	if (line == NULL)
 		return (0);
 	while (line[i] != '\0') //? itera toda la string
 	{
 		if (line[i] == '\n') //? si encuentra salto de linea devuelve 1
 			return (1);
 		i++;
 	}
 	return(0); //? despues de iterar la string y no encuentra salto de linea devuelve 0
 }

char	*ft_read(int fd) //? lee y devuelve string
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc (BUFFER_SIZE + 1);
	//printf("[%p]\n", buffer);
	if (!buffer)
		return (NULL);
	bytes_read = read (fd, buffer, BUFFER_SIZE);
	if (bytes_read == -1)
	{
		free (buffer);
		return (NULL);
	}
	buffer[bytes_read] = '\0';
	printf ("%s\n", buffer);
	return (buffer);
}

char	*ft_line(char	*s, int fd) //? se usa para detectar la primera linea de texto de una cadena de caracteres
{
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	while (!salto(line)) //? es verdadero cuando no ahi salto de linea en line 
	{
		//line = ft_read(fd); //? guarda el contenido de ft_read en line y no tiene que ser una linea completa
		line = ft_strjoin (line, ft_read(fd));
	}
	if (line == NULL)
	{
		return (NULL);
	}
	return (line);
}

int	ft_saltlin(char *line)//? devuelve la posicion del salto de linea, si no hay salto de linea devuelve el nº de char que ahi
{
	int i;

	i = 0;
	while (line[i] != '\0')//? Busca el nulo, busca la posicion del salto de linea, para, devuelve el nº
	{
		if(line[i] == '\n')//?Busca el salto de linea y devuelve el index.
			return(i);
		i++;
	}
	return(i);//?cuando no ahi un salto de linea devuelve 
}

//? guardar los caracteres usando strjoin
char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE<= 0)
		return (0);
	if (!save)
		return (NULL);
	line = ft_line (save, fd); //?devuelme una linea o mas
	int i = ft_saltlin(line);
	if(line[i] == '\n')
	{
		line = ft_substr(line, 0, i + 1); //? para que empiece por el char 0 le pongo 0 y lo de i + 1 es para devolver la longitud de la cadena a devolver
		save = ft_substr(line, i + 1, ft_strlen(line + i + 1)); //? la primera parte sirve para que sepa donde empezar, la segunda es para qu eccuenta la segunda parte
	}
	if (line == NULL)
		return (NULL);
	return (line);
}

/*
orden
encontrar salto de linea 
cortar la string donde este el salto de linea 
*/