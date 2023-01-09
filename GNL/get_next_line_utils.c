/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuesta- <acuesta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 10:22:51 by acuesta-          #+#    #+#             */
/*   Updated: 2023/01/09 13:27:52 by acuesta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	c;

	c = 0;
	if (!str)
		return(0);
	while(str[c] != '\0')
		c++;
	return (c);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	y1;
	unsigned int	y2;
	unsigned int	i;
	unsigned int	x;
	char			*str1;

	if (s1 == 0 || s2 == 0)
		return (NULL);
	y1 = ft_strlen(s1);
	y2 = ft_strlen(s2);
	i = 0;
	x = -1;
	str1 = malloc(sizeof(char) * (y1 + y2 + 1));
	if (!str1)
		return (NULL);
	while (s1[i])
	{
		str1[i] = s1[i];
		i++;
	}
	while (s2[++x])
		str1[i++] = s2[x];
	str1[i] = '\0';
	return (str1);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*memory;
	size_t	i;

	i = 0;
	memory = malloc(count * size);
	if (memory == NULL)
		return (0);
	while (i < count * size)
	{
		memory[i] = 0;
		i++;
	}
	return (memory);
}

char	*ft_strchr(const char *s, int c)
{
	char	*chr;

	chr = (char *)s;
	while (*chr != (const char)c)
	{
		if (!*chr)
			return (NULL);
		chr++;
	}
	return (chr);
}