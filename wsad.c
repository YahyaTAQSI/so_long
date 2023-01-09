/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wsad.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaqsi <ytaqsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:50:37 by ytaqsi            #+#    #+#             */
/*   Updated: 2023/01/07 18:05:44 by ytaqsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clear_exit(t_maps *m, int bonus)
{
	if (bonus)
		write(1, "You Lose !!!\n", 13);
	else
		write(1, "You Won !!!\n", 12);
	clearall(m);
	exit(bonus);
}

void	ifup(t_maps *m)
{
	if (m->str[m->px - 1][m->py] == 'A')
		clear_exit(m, 1);
	if (m->str[m->px - 1][m->py] == 'E' && m->c->c_cp == 0)
		clear_exit(m, 0);
	manipulate(m, -1, 0, &m->moves);
	m->player
		= mlx_xpm_file_to_image(m->mlx, "./img/p/w.xpm", &m->x, &m->y);
}

void	ifdown(t_maps *m)
{
	if (m->str[m->px + 1][m->py] == 'A')
		clear_exit(m, 1);
	if (m->str[m->px + 1][m->py] == 'E' && m->c->c_cp == 0)
		clear_exit(m, 0);
	manipulate(m, 1, 0, &m->moves);
	m->player
		= mlx_xpm_file_to_image(m->mlx, "./img/p/s.xpm", &m->x, &m->y);
}

void	ifright(t_maps *m)
{
	if (m->str[m->px][m->py + 1] == 'A')
		clear_exit(m, 1);
	if (m->str[m->px][m->py + 1] == 'E' && m->c->c_cp == 0)
		clear_exit(m, 0);
	manipulate(m, 0, 1, &m->moves);
	m->player
		= mlx_xpm_file_to_image(m->mlx, "./img/p/d.xpm", &m->x, &m->y);
}

void	ifleft(t_maps *m)
{
	if (m->str[m->px][m->py - 1] == 'A')
		clear_exit(m, 1);
	if (m->str[m->px][m->py - 1] == 'E' && m->c->c_cp == 0)
		clear_exit(m, 0);
	manipulate(m, 0, -1, &m->moves);
	m->player
		= mlx_xpm_file_to_image(m->mlx, "./img/p/a.xpm", &m->x, &m->y);
}
