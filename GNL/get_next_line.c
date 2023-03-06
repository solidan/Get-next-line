/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuesta- <acuesta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 10:22:43 by acuesta-          #+#    #+#             */
/*   Updated: 2023/03/02 11:34:34 by acuesta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

 int	salto(char *line)//? busca salto de linea. si es verdadero entonces devuelve 1 y si es false devuelve 0 
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
	if (buffer == NULL) //? esto se activa cuando malloc da error
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE); //? cuando fd falla, cuando el buffer no tiene suficiente espcio, BSes negativo, // devuelve el nº de bytes leidos
	if (bytes_read < 0)
	{
		return (NULL);
	}
	buffer[bytes_read] = '\0';
	return (buffer);
}

char	*ft_string(char *save, int fd) //? cuando consiga una string con salto de linea o caundo se acaba el archivo la devuelve
{
	char	*string;
	char	*temp;
	char	*lib;

	string = NULL;
	
	if (save)
		string = save; //? Uso strdup para que copie la cadena save y que la almacene en string
	while (!salto(string)) //? es verdadero mientras no ahi salto de linea en la string
	{
		temp = ft_read(fd);
		if(temp[0] == '\0')
		{
			free (temp);
			return (string);
		}
		if (temp == NULL)
			return (string);	
	 	lib = ft_strjoin (string, temp); 
		if(string == NULL)
			free (string);
		free (temp);
		string = lib;
	}
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
	static char	*save = NULL; //? se pone estatica para que vuelva a empezar y evitar null
	int			i;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	line = ft_string (save, fd); //?devuelme una linea o mas
	if (line == NULL)
		return (NULL);
	i = ft_saltlin(line);
	if (line[i] == '\n') //? Para encontrar el salto de linea
	{
		save = ft_substr (line, i + 1, ft_strlen(line + i + 1)); //? la primera parte sirve para que sepa donde empezar, la segunda es para qu eccuenta la segunda parte
		temp = ft_substr (line, 0, i + 1); //? para que empiece por el char 0 le pongo 0 y lo de i + 1 es para devolver la longitud de la cadena a devolver	
		free(line);
		line = temp;
	}
	//?hacer algo para que no se repita la ultima linea y que pasa cuando no encuentra un salto de linea
    else
		save = NULL; //? Sirve para que no repita la ultima linea
	if (line[0] == '\0') //? si la primera posicion de line es "vacio" que devuelva nulo
	{
		free (line);
		return (NULL);
	}
	return (line);
}
//? la estatica En este proyecto, una variable estática es 
//? necesaria para almacenar los caracteres extra,  leídos después
//? de un \ne. De esta manera, cuando  llamemos de nuevo a
//? get_next_line para obtener la  siguiente línea, esos caractres
//? no se perderán. Sirve para que empiece a leer desde donde termino y que no repita lo que ha leido
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