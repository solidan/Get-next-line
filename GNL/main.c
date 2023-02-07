/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuesta- <acuesta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:58:41 by acuesta-          #+#    #+#             */
/*   Updated: 2023/02/07 13:36:20 by acuesta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>	
#include <stdlib.h>	
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "get_next_line.h"
// char *get_next_line(int fd)
// {
//  	char *str;	
//   	str = malloc(42);
//   	size_t bytes = read(fd, str, 40);
//  	if (bytes == -1)
// 	{
//  		return (0);
// 	}
//   	return (str);
// 	printf("Read %ld bytes: %s\n", bytes, str);
// }
// int main(void)
// {
//  	int fd;
//  	char *str;
// 	fd = open("prueba.txt", O_RDONLY);
//  	if (fd == -1)
//  	return (-1);
//  	str = get_next_line(fd);
// 	free(str);
// 	if(close(fd) == -1)
// 	{
// 		return (0);
// 	}
//  	return (0);
// }
/*int main() 
 {
   // Open a file for reading
   int fd = open("prueba.txt", O_RDONLY);
   if (fd == -1) {
     return (1);
   }
   // Read data from the file
   char str[42];
   size_t bytes_read = read(fd, str, sizeof(str));
   if (bytes_read == -1) {
     perror("Error reading from file");
     return 1;
   }
   // Print the data that was read
   printf("Read %ld bytes: %s\n", bytes_read, str);
   printf("Read %ld bytes: %s\n", bytes_read, str);
 //long int
   // Close the file
   if (close(fd) == -1) 
   {
     return 1;
   }
   return 0;
 }*/
//* tipo nombre(tipo var, tipo var2,...){
//** conjunto de instrucciones;
//*
// int contador(int n, char s)
// {
// 	int b;
// if (s == 'a')
// {
// 	b = n / 4;
// 	return(b);
// }
// else if(s == 'i')
// {
// 	b = n / 2;
// 	return(b);
// }
// return(0);
// }
// int main(void){
// 	printf("%d", contador(8, 'i'));
// }
// #include <stdio.h>
// #include <stdlib.h>
// #include <sys/types.h>
// #include <sys/stat.h>
// #include <fcntl.h>

int main(void) 
{

   int fd = open("prueba.txt", O_RDONLY);
   if (fd == -1) 
   {
    return 1;
   }
	char *line = get_next_line(fd);
	printf("[%s]\n",line);
	line = get_next_line(fd);
	printf("[%s]\n",line);
	line = get_next_line(fd);
	printf("[%s]\n",line);
	line = get_next_line(fd);
	printf("[%s]\n",line);
	line = get_next_line(fd);
	printf("[%s]\n",line);
	line = get_next_line(fd);
	printf("[%s]\n",line);
	return(0);
}
