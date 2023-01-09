/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaqsi <ytaqsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:07:19 by ytaqsi            #+#    #+#             */
/*   Updated: 2023/01/04 16:38:46 by ytaqsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	intl(long n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		i++;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*p;
	long	ln;

	i = intl((long)n);
	ln = (long)n;
	p = (char *)malloc((i + 1) * sizeof(char));
	if (!p)
		return (NULL);
	p[i] = '\0';
	i--;
	if (ln < 0)
		ln = -ln;
	while (i > 0)
	{
		p[i] = ln % 10 + '0';
		ln /= 10;
		i--;
	}
	if (n < 0)
		p[i] = '-';
	else if (n >= 0)
		p[i] = ln + '0';
	return (p);
}
