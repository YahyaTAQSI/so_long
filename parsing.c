/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaqsi <ytaqsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:00:21 by ytaqsi            #+#    #+#             */
/*   Updated: 2023/01/08 15:28:08 by ytaqsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	freestr(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = ft_strlen(str) - 1;
	if ((char)c == '\0')
		return ((char *)(str + i + 1));
	while (i >= 0)
	{
		if ((char)c == str[i])
			return ((char *)(str + i));
		i--;
	}
	return (NULL);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	closewin(t_maps *m)
{
	clearall(m);
	exit(0);
}

void	ft_parsing(int ac, char *av[], t_maps *maps)
{
	char	**map;

	maps->str = NULL;
	maps->mlx = mlx_init();
	if (ac == 2 && !ft_strcmp(av[1] + ft_strlen(av[1]) - 4, ".ber"))
	{
		maps->str = fillarr(av[1]);
		map = fillarr(av[1]);
	}
	if (!maps->str || !maps->mlx || !checklh(maps->str) || !checkone(maps->str)
		|| !checkmap(maps) || !backtracking(map))
	{
		write(2, "Error\n", 6);
		if (maps->str)
			freestr(maps->str);
		exit(1);
	}
	show_window(maps);
	graphics(maps);
	mlx_hook(maps->win, 2, 0, movepalyer, maps);
	if (maps->bonus)
		mlx_loop_hook(maps->mlx, moveenemy, maps);
	mlx_hook(maps->win, 17, 0, closewin, maps);
	mlx_loop(maps->mlx);
}
