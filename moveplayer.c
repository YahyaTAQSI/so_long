/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveplayer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaqsi <ytaqsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:23:58 by ytaqsi            #+#    #+#             */
/*   Updated: 2023/01/08 15:54:35 by ytaqsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd >= 0)
		write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = n * -1;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		ft_putchar_fd(n + 48, fd);
	}
}

void	manipulate(t_maps *m, int i, int j, int *moves)
{
	if (m->str[m->px + i][m->py + j] == '1'
		|| (m->str[m->px + i][m->py + j] == 'E' && m->c->c_cp > 0))
		return ;
	if (m->str[m->px + i][m->py + j] == 'C')
			m->c->c_cp--;
	(*moves)++;
	if (!m->bonus)
	{
		ft_putnbr_fd(*moves, 1);
		write(1, " moves\n", 7);
	}
	m->str[m->px][m->py] = '0';
	m->str[m->px + i][m->py + j] = 'P';
	if (i < 0)
		m->px--;
	if (i > 0)
		m->px++;
	if (j < 0)
		m->py--;
	if (j > 0)
		m->py++;
	mlx_destroy_image(m->mlx, m->player);
}

void	ifmoved(int key, t_maps *m)
{
	if (key == 13 || key == 126)
		ifup(m);
	if (key == 1 || key == 125)
		ifdown(m);
	if (key == 2 || key == 124)
		ifright(m);
	if (key == 0 || key == 123)
		ifleft(m);
}

int	movepalyer(int key, t_maps *m)
{
	if (key == 53)
	{
		clearall(m);
		exit(0);
	}
	if (key == 13 || key == 1 || key == 2 || key == 0
		|| key == 123 || key == 124 || key == 125 || key == 126)
	{
		ifmoved(key, m);
		if (!m->bonus)
			graphics(m);
	}
	return (1);
}
