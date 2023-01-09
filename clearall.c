/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clearall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaqsi <ytaqsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:16:41 by ytaqsi            #+#    #+#             */
/*   Updated: 2023/01/08 15:29:36 by ytaqsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clearall(t_maps *m)
{
	if (m->str)
		freestr(m->str);
	if (m->wall)
		mlx_destroy_image(m->mlx, m->wall);
	if (m->ground)
		mlx_destroy_image(m->mlx, m->ground);
	if (m->player)
		mlx_destroy_image(m->mlx, m->player);
	if (m->collect)
		mlx_destroy_image(m->mlx, m->collect);
	if (m->door)
		mlx_destroy_image(m->mlx, m->door);
	if (m->enemy)
		mlx_destroy_image(m->mlx, m->enemy);
	if (m->win)
		mlx_destroy_window(m->mlx, m->win);
}

void	randomove(int *x, int *y)
{
	int	r;

	*x = rand() % 3 - 1;
	*y = rand() % 3 - 1;
	r = rand() % 2;
	if (r)
		*x = 0;
	else
		*y = 0;
}

void	printfmoves(t_maps *maps)
{
	char	*s;

	s = ft_itoa(maps->moves);
	mlx_string_put(maps->mlx, maps->win, 26, 24, 0xFFFFFF, s);
	free(s);
}

void	ifp(t_maps *m)
{
	write(1, "You Lose!!\n", 11);
	clearall(m);
	exit(0);
}

void	clearanimation(t_maps *m, int i)
{
	if ((i == 0 || i == 5 || i == 10 || i == 15
			|| i == 20 || i == 25 || i == 30 || i == 35) && m->collect)
		mlx_destroy_image(m->mlx, m->collect);
}
