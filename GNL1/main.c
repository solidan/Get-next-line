/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuesta- <acuesta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 10:44:48 by acuesta-          #+#    #+#             */
/*   Updated: 2023/02/13 11:48:07 by acuesta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>	
#include <stdlib.h>	
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open ("prueba.txt", O_RDONLY);
	if (fd == -1)
		return (1);
line = get_next_line (fd);
printf ("[%s]\n",line);
line = get_next_line (fd);
printf ("[%s]\n",line);
line = get_next_line(fd);
printf ("[%s]\n",line);
line = get_next_line(fd);
printf("[%s]\n",line);
line = get_next_line(fd);
printf("[%s]\n",line);
line = get_next_line(fd);
printf("[%s]\n",line);
return(0);
}