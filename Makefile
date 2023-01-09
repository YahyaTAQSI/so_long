# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytaqsi <ytaqsi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 13:42:44 by ytaqsi            #+#    #+#              #
#    Updated: 2023/01/06 16:53:20 by ytaqsi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit
FRM = rm -rf

NAME = so_long
BONUS = so_long_pro
HEADER = so_long.h

SRCMAN = checkmap.c \
	get_next_line.c \
	backtracking.c \
	moveplayer.c \
	ft_split.c \
	showmaps.c \
	clearall.c\
	parsing.c \
	so_long.c \
	wsad.c \
	itoa.c \
	enemy.c\

SRCBNS = checkmap.c \
	get_next_line.c \
	backtracking.c \
	so_long_pro.c \
	moveplayer.c \
	ft_split.c \
	showmaps.c \
	clearall.c\
	parsing.c \
	wsad.c \
	itoa.c \
	enemy.c\

all: $(NAME)

$(NAME): $(SRCMAN) $(HEADER)
	$(CC) $(CFLAGS) $(SRCMAN) -o $(NAME)

$(BONUS): $(SRCBNS) $(HEADER)
	$(CC) $(CFLAGS) $(SRCBNS) -o $(BONUS)

bonus: $(BONUS)

clean:
	$(FRM) $(NAME)

fclean: clean
	$(FRM) $(BONUS)

re: fclean all
