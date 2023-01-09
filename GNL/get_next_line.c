/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuesta- <acuesta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 10:22:43 by acuesta-          #+#    #+#             */
/*   Updated: 2023/01/09 13:12:26 by acuesta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//! Variables estatica: la diferencia este que no se puede acceder a esta variable desde otro archivo y es necesaria para mantener la lectura de linea con la cantidad de BUFFER_SIZE
//!
#include "get_next_line.h"

char	*ft_free(char *buffer)
{
	char	*temp;
	temp = ft_strjoin(buffer);
	free(buffer);
	return(temp);
}

char *ft_next(char *buffer)
{
	int	i;
	int	j;
	char	*line;
	
	i = 0;
	j = 0;
	while (buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return(NULL);
	}
}
