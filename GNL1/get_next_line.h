/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuesta- <acuesta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 10:35:35 by acuesta-          #+#    #+#             */
/*   Updated: 2023/03/06 12:23:59 by acuesta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h> 
# include <string.h>
# include <unistd.h>

char	*get_next_line(int fd);
int		salto(char	*line);
char	*ft_read(int fd);
char	*ft_string(char	*save, int fd);
int		ft_saltlin(char *line);
size_t	ft_strlen(char *str);
char	*ft_substr(char *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char *s1, char *s2);
char	*read_line(int fd, char **save);

#endif 