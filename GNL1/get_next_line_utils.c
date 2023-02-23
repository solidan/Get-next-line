/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuesta- <acuesta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 10:35:38 by acuesta-          #+#    #+#             */
/*   Updated: 2023/02/13 10:54:14 by acuesta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	c;

	c = 0;
	if (str == NULL)
	{
		return (0);
	}
	while (str[c] != '\0')
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

	if (s2 == 0)
		return (NULL);
	y1 = ft_strlen((char *)s1);
	y2 = ft_strlen((char *)s2);
	i = 0;
	x = -1;
	str1 = malloc(sizeof(char) * (y1 + y2 + 1));
	if (!str1)
		return (NULL);
	while (i < y1)
	{
		str1[i] = s1[i];
		i++;
	}
	while (s2[++x])
		str1[i++] = s2[x];
	str1[i] = '\0';
	return (str1);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	char	*pt_src;

	pt_src = (char *)src;
	i = 0;
	if (dstsize > 0)
	{
		while (pt_src[i] && i < dstsize - 1)
		{
			dst[i] = pt_src[i];
			i++;
		}
		dst[i] = 0;
	}
	while (src[i])
		i++;
	return (i);
}

char	*ft_substr(char *s, unsigned int start, size_t len)

{
	char	*i;

	if (len > ft_strlen(s))
	{
		len = ft_strlen(s);
	}
	i = (char *)malloc(len + 1);
	if (start > ft_strlen(s))
	{
		*i = '\0';
		return (i);
	}
	if (!i)
	{
		return (0);
	}
	ft_strlcpy(i, &s[start], len + 1);
	return (i);
}
