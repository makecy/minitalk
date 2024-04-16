/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:36:41 by mstefano          #+#    #+#             */
/*   Updated: 2024/04/03 19:54:11 by mstefano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	if (!s)
		return (0);
	while (s[count])
		count++;
	return (count);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	str = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!str)
		return (free (s1), str = NULL);
	while (s1 && s1[i] != 0)
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j] != 0)
	{
		str[i + j] = s2[j];
		j++;
	}
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	if (s1)
		free(s1);
	return (str);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total;
	void	*ptr;

	total = count * size;
	printf("total %s\n", total);
	ptr = malloc(total);
	if (ptr != NULL)
		ft_memset(ptr, 0, total);
	return (ptr);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*a;

	a = (unsigned char *)b;
	while (len > 0)
	{
		*a = (unsigned char)c;
		a++;
		len--;
	}
	return (b);
}
