/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaqsi <ytaqsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:40:42 by ytaqsi            #+#    #+#             */
/*   Updated: 2023/01/08 15:39:04 by ytaqsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	position(char **str, char c, int i, int j)
{
	if (str[i][j] == 'P')
		return (1);
	if (str[i][j] == '1' || (c != 'E' && str[i][j] == 'E'))
		return (0);
	str[i][j] = '1';
	if (position(str, c, i, j + 1))
		return (1);
	if (position(str, c, i, j - 1))
		return (1);
	if (position(str, c, i + 1, j))
		return (1);
	if (position(str, c, i - 1, j))
		return (1);
	return (0);
}

char	**copymap(char **s)
{
	int		i;
	int		l;
	char	**p;

	i = 0;
	l = -1;
	while (s[i])
		i++;
	p = malloc((i + 1) * sizeof(char *));
	if (!p)
		return (NULL);
	while (++l < i)
		p[l] = ft_strdup(s[l]);
	p[l] = NULL;
	return (p);
}

int	backtracking(char **str)
{
	int		ij[2];
	int		cp;
	char	**test;

	cp = 0;
	ij[0] = -1;
	while (str[++ij[0]])
	{
		ij[1] = -1;
		while (str[ij[0]][++ij[1]])
		{
			if (str[ij[0]][ij[1]] == 'C' || str[ij[0]][ij[1]] == 'E')
			{
				test = copymap(str);
				if (!test)
					return (freestr(str), 0);
				if (!position(test, test[ij[0]][ij[1]], ij[0], ij[1]))
					cp++;
				freestr(test);
			}
		}
	}
	if (cp == 0)
		return (freestr(str), 1);
	return (freestr(str), 0);
}
