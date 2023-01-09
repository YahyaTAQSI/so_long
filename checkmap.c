/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaqsi <ytaqsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:59:00 by ytaqsi            #+#    #+#             */
/*   Updated: 2023/01/07 12:11:02 by ytaqsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**fillarr(const char *s)
{
	char	*res;
	char	*tmp;
	char	**rst;
	int		fd;

	fd = open(s, O_RDONLY);
	if (fd < 0)
		return (NULL);
	res = NULL;
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp || tmp[0] == '\n')
			return (free (tmp), NULL);
		if (!tmp[0])
			break ;
		res = ft_strjoin(res, tmp);
		free (tmp);
	}
	rst = ft_split(res, '\n');
	free(res);
	return (free (tmp), rst);
}

int	checklh(char **str)
{
	int	i;
	int	pl;
	int	l;

	if (!str)
		return (0);
	i = 0;
	pl = ft_strlen(str[i]);
	while (str[i])
	{
		l = ft_strlen(str[i++]);
		if (l != pl)
			return (0);
	}
	if (pl == i)
		return (0);
	return (1);
}

int	checkone(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i][j] == '1')
		j++;
	if (j != ft_strlen(str[i]))
		return (0);
	j--;
	while (str[i] && str[i][j] == '1')
		i++;
	if (str[i])
		return (0);
	i--;
	while (str[i][j] == '1' && j > 0)
		j--;
	if (j != 0)
		return (0);
	while (str[i][j] == '1' && i > 0)
		i--;
	if (i == 0 && j == 0)
		return (1);
	return (0);
}

int	ifnot(char c, t_maps *m, int *ij)
{
	if (m->bonus)
	{
		if (c != '0' && c != '1' && c != 'C'
			&& c != 'E' && c != 'P' && c != 'A')
			return (0);
	}
	else
	{
		if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P')
			return (0);
	}
	if (c == 'C')
		m->c->c_cp++;
	if (c == 'E')
		m->c->e_cp++;
	if (c == 'A')
		m->c->a_cp++;
	if (c == 'P')
	{
		m->px = ij[0];
		m->py = ij[1];
		m->c->p_cp++;
	}
	return (1);
}

int	checkmap(t_maps *cp)
{
	int	i;
	int	j;
	int	ij[2];

	cp->c->c_cp = 0;
	cp->c->e_cp = 0;
	cp->c->p_cp = 0;
	cp->c->a_cp = 0;
	i = -1;
	while (cp->str[++i])
	{
		j = 0;
		while (cp->str[i][j])
		{
			ij[0] = i;
			ij[1] = j;
			if (!ifnot(cp->str[i][j], cp, ij))
				return (0);
			j++;
		}
	}
	if (cp->c->e_cp != 1 || cp->c->p_cp != 1
		|| cp->c->c_cp < 1 || (cp->bonus && cp->c->a_cp < 1))
		return (0);
	return (1);
}
