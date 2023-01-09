/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaqsi <ytaqsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:39:57 by ytaqsi            #+#    #+#             */
/*   Updated: 2023/01/08 15:29:46 by ytaqsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <mlx.h>
# include <stdio.h>
# include <time.h>

typedef struct s_counts
{
	int			p_cp;
	int			e_cp;
	int			c_cp;
	int			a_cp;
}				t_counts;

typedef struct s_maps
{
	t_counts	*c;
	int			px;
	int			py;
	int			bonus;
	int			moves;
	char		**str;
	void		*mlx;
	void		*win;
	void		*wall;
	void		*ground;
	void		*player;
	void		*door;
	void		*enemy;
	void		*collect;
	int			x;
	int			y;
	int			i;
	int			j;
}				t_maps;

char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s1);
char	*get_next_line(int fd);
int		ft_strlen(const char *s);
char	**fillarr(const char *s);
int		checklh(char **str);
int		checkone(char **str);
int		ifnot(char c, t_maps *m, int *ij);
int		checkmap(t_maps *cp);
char	*ft_strrchr(const char *str, int c);
int		ft_strcmp(char *s1, char *s2);
void	ft_parsing(int ac, char *av[], t_maps *p);
int		backtracking(char **str);
void	freestr(char **str);
void	show_window(t_maps *maps);
void	graphics(t_maps *maps);
int		movepalyer(int key, t_maps *m);
void	ifup(t_maps *m);
void	ifdown(t_maps *m);
void	ifright(t_maps *m);
void	ifleft(t_maps *m);
void	manipulate(t_maps *m, int i, int j, int *moves);
void	clearall(t_maps *m);
char	*ft_itoa(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	printmoves(t_maps *m, int *moves);
void	checkpath(t_maps *m);
void	printfmoves(t_maps *maps);
int		moveenemy(t_maps *m);
void	spawnall(t_maps *m, char c);
void	printfmoves(t_maps *maps);
void	ifp(t_maps *m);
void	randomove(int *x, int *y);
void	clearanimation(t_maps *m, int i);

#endif
