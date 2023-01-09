/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaqsi <ytaqsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:31:02 by ytaqsi            #+#    #+#             */
/*   Updated: 2023/01/08 15:54:23 by ytaqsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ewsad(t_maps *m, int x, int y)
{
	if (m->enemy)
		mlx_destroy_image(m->mlx, m->enemy);
	if (x < 0)
		m->enemy = mlx_xpm_file_to_image(m->mlx, "./img/e/w.xpm", &m->x, &m->y);
	if (x > 0)
		m->enemy = mlx_xpm_file_to_image(m->mlx, "./img/e/s.xpm", &m->x, &m->y);
	if (y < 0)
		m->enemy = mlx_xpm_file_to_image(m->mlx, "./img/e/a.xpm", &m->x, &m->y);
	if (y > 0)
		m->enemy = mlx_xpm_file_to_image(m->mlx, "./img/e/d.xpm", &m->x, &m->y);
}

void	manipulatenemy(t_maps *m, int *x, int *y)
{
	int	i;
	int	j;

	i = -1;
	while (m->str[++i])
	{
		j = -1;
		while (m->str[i][++j])
		{
			if (m->str[i][j] == 'A')
			{
				randomove(x, y);
				if (m->str[i + *x][j + *y] == 'P')
					ifp(m);
				if (m->str[i + *x][j + *y] == '0')
				{
					m->str[i][j] = '0';
					m->str[i + *x][j + *y] = 'A';
					ewsad(m, *x, *y);
				}
			}
		}
	}
}

void	ifenmoved(t_maps *m)
{
	int	x;
	int	y;

	manipulatenemy(m, &x, &y);
}

void	animatecoll(t_maps *m, int i)
{
	clearanimation(m, i);
	if (i == 0)
		m->collect
			= mlx_xpm_file_to_image(m->mlx, "./img/c/0.xpm", &m->x, &m->y);
	if (i == 5)
		m->collect
			= mlx_xpm_file_to_image(m->mlx, "./img/c/1.xpm", &m->x, &m->y);
	if (i == 10)
		m->collect
			= mlx_xpm_file_to_image(m->mlx, "./img/c/2.xpm", &m->x, &m->y);
	if (i == 15)
		m->collect
			= mlx_xpm_file_to_image(m->mlx, "./img/c/3.xpm", &m->x, &m->y);
	if (i == 20)
		m->collect
			= mlx_xpm_file_to_image(m->mlx, "./img/c/4.xpm", &m->x, &m->y);
	if (i == 25)
		m->collect
			= mlx_xpm_file_to_image(m->mlx, "./img/c/5.xpm", &m->x, &m->y);
	if (i == 30)
		m->collect
			= mlx_xpm_file_to_image(m->mlx, "./img/c/6.xpm", &m->x, &m->y);
	if (i == 35)
		m->collect
			= mlx_xpm_file_to_image(m->mlx, "./img/c/7.xpm", &m->x, &m->y);
}

int	moveenemy(t_maps *m)
{
	static int	i;
	static int	j;

	if (j == 36)
		j = 0;
	animatecoll(m, j);
	if (i == 20)
	{
		i = 0;
		ifenmoved(m);
	}
	i++;
	j++;
	graphics(m);
	return (1);
}
