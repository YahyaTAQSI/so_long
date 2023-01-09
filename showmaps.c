/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   showmaps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaqsi <ytaqsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 17:57:23 by ytaqsi            #+#    #+#             */
/*   Updated: 2023/01/07 18:24:34 by ytaqsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	imginit(t_maps *maps)
{
	maps->ground
		= mlx_xpm_file_to_image(maps->mlx, "./img/0.xpm", &maps->x, &maps->y);
	maps->collect
		= mlx_xpm_file_to_image(maps->mlx, "./img/c/0.xpm", &maps->x, &maps->y);
	maps->wall
		= mlx_xpm_file_to_image(maps->mlx, "./img/1.xpm", &maps->x, &maps->y);
	maps->door
		= mlx_xpm_file_to_image(maps->mlx, "./img/e.xpm", &maps->x, &maps->y);
	maps->player
		= mlx_xpm_file_to_image(maps->mlx, "./img/p/d.xpm", &maps->x, &maps->y);
	if (maps->bonus)
		maps->enemy
			= mlx_xpm_file_to_image(maps->mlx,
				"./img/e/d.xpm", &maps->x, &maps->y);
}

void	spawnall(t_maps *m, char c)
{
	if (c == '1')
		mlx_put_image_to_window(m->mlx, m->win, m->wall, m->x, m->y);
	else
		mlx_put_image_to_window(m->mlx, m->win, m->ground, m->x, m->y);
	if (c == 'P')
		mlx_put_image_to_window(m->mlx, m->win, m->player, m->x, m->y);
	if (c == 'E')
		mlx_put_image_to_window(m->mlx, m->win, m->door, m->x, m->y);
	if (c == 'C')
		mlx_put_image_to_window(m->mlx, m->win, m->collect, m->x, m->y);
	if (c == 'A' && m->bonus)
		mlx_put_image_to_window(m->mlx, m->win, m->enemy, m->x, m->y);
}

void	checkpath(t_maps *m)
{
	if (!m->ground || !m->collect
		|| !m->wall || !m->door || !m->player || (m->bonus && !m->enemy))
	{
		clearall(m);
		write(2, "Wrong Path\n", 11);
		exit(1);
	}
}

void	graphics(t_maps *maps)
{
	checkpath(maps);
	mlx_clear_window(maps->mlx, maps->win);
	maps->i = 0;
	maps->j = 0;
	maps->x = 0;
	maps->y = 0;
	while (maps->str[maps->i])
	{
		maps->j = 0;
		maps->x = 0;
		while (maps->str[maps->i][maps->j])
		{
			spawnall(maps, maps->str[maps->i][maps->j]);
			maps->x = (++maps->j) * 64;
		}
		maps->y = (++maps->i) * 64;
	}
	if (maps->bonus)
		printfmoves(maps);
}

void	show_window(t_maps *maps)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	maps->moves = 0;
	while (maps->str[i][j])
		j++;
	while (maps->str[i])
		i++;
	imginit(maps);
	maps->win = mlx_new_window(maps->mlx, j * 64, i * 64, "so_long");
}
