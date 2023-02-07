/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuesta- <acuesta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 10:22:43 by acuesta-          #+#    #+#             */
/*   Updated: 2023/02/07 13:59:57 by acuesta-         ###   ########.fr       */
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

	buffer = malloc(BUFFER_SIZE + 1);
	//printf("[%p]\n", buffer);
	if (buffer == NULL) //? esto se activa cuando malloc da error
		return (NULL);
	//printf("malloc no tiene la culpa[%p]\n", buffer);
	bytes_read = read(fd, buffer, BUFFER_SIZE); //? cuando fd falla, cuando el buffer no tiene suficiente espcio, BSes negativo, // devuelve el nº de bytes leidos
	if (bytes_read < 0)
	{
		free (buffer);
		return (NULL);
	}
	//printf("read no tiene la culpa\n");
	buffer[bytes_read] = '\0';
	//printf("buffer = [%s]\n, bytes_read = %d \n", buffer, bytes_read);
	return (buffer);
}

char	*ft_string(char *save, int fd) //? cuando consiga una string con salto de linea  la devuelve
{
	char	*string;
	char	*temp;
	int		i;

	i = 0;
	string = NULL;
	if (save)
		return (save);
	while (!salto(string)) //? es verdadero cuando no ahi salto de linea en line 
	{
		//line = ft_read(fd); //? guarda el contenido de ft_read en line y no tiene que ser una linea completa
		temp = ft_read(fd);
		if(temp[0] == '\0'){
			return(NULL);
		}
		
		if(temp == NULL)
		{
			return(string);	
		}
		//printf("2");
		string = ft_strjoin (string, temp);
		//printf("[%s]\n", temp);
	}
	//printf("3");
	return (string);
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
	static char	*save = NULL;

	if (fd < 0 || BUFFER_SIZE<= 0)
		return (0);
	//if(save)
	//	return save;
	//printf("1\n");
	line = ft_string (save, fd); //?devuelme una linea o mas
	
	if (line == NULL)
		return(NULL);
	//printf("2");
	int i = ft_saltlin(line);
	if(line[i] == '\n')
	{
		save = ft_substr(line, i + 1, ft_strlen(line + i + 1)); //? la primera parte sirve para que sepa donde empezar, la segunda es para qu eccuenta la segunda parte
		line = ft_substr(line, 0, i + 1); //? para que empiece por el char 0 le pongo 0 y lo de i + 1 es para devolver la longitud de la cadena a devolver
	}
	//printf("3\n");
	if (!line)
		return (NULL);
		//printf("3");
	return (line);
}

/*
Read sirve para leer datos de un fd y los almacena en un buffer la sintaxis es mas o menos asi read(fd, buffer, BUFFER_SIZE)

GNL sirve para leer linea a linea

la variable estatica es una variable que mantiene su valor continuamente
y en el caso de GNL es para que no repita la linea
*/

/*
orden
encontrar salto de linea 
cortar la string donde este el salto de linea 
*/