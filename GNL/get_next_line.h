/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuesta- <acuesta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 10:22:48 by acuesta-          #+#    #+#             */
/*   Updated: 2023/02/07 12:23:45 by acuesta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


char	*get_next_line(int fd);
int		salto(char	*line);
char	*ft_read(int fd);
char	*ft_string(char  *save, int fd);
int		ft_saltlin(char *line);
size_t	ft_strlen(char *str);
char	*ft_substr(char *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char const *s1, char const *s2);

#endif 