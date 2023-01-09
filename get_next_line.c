/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaqsi <ytaqsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:44:14 by ytaqsi            #+#    #+#             */
/*   Updated: 2023/01/08 15:39:23 by ytaqsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		is1;
	int		is2;
	char	*p;

	is1 = ft_strlen(s1);
	is2 = ft_strlen(s2);
	p = (char *)malloc((is1 + is2 + 1) * sizeof(char));
	if (!p)
		return (NULL);
	is1 = 0;
	is2 = 0;
	while (s1 && s1[is1])
	{
		p[is1] = s1[is1];
		is1++;
	}
	while (s2[is2])
		p[is1++] = s2[is2++];
	p[is1] = '\0';
	free(s1);
	s1 = NULL;
	return (p);
}

char	*ft_strdup(const char *s1)
{
	char	*copy;
	int		i;

	copy = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*get_next_line(int fd)
{
	char	buff[8000000];
	char	c;
	int		i;

	i = 0;
	while (read(fd, &c, 1))
	{
		buff[i] = c;
		i++;
		if (c == '\n')
			break ;
	}
	buff[i] = 0;
	return (ft_strdup(buff));
}
