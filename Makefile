# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eghaffar <eghaffar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 10:40:03 by eghaffar           #+#    #+#              #
#    Updated: 2024/03/21 11:19:10 by eghaffar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= cub3D
SRC_DIR		:= src
SRCS		:= 	\
			init/init.c \
			file/read_file.c \
			map/map.c \
			map/map_around.c \
			map/final_map.c \
			map/map_content.c \
			parsing/extension.c \
			parsing/analysis.c \
			parsing/tc_utils.c \
			parsing/main.c \
			parsing/textures_and_colors.c \
			parsing/colorstr_to_int.c \
			parsing/is_map_valid.c \
			parsing/tools_map_valid.c \
			utils/utils.c \
			utils/utils2.c \
			utils/debugg.c \
			utils/cleaning.c\
			exec_mon_gars/exec.c \
			exec_mon_gars/start_the_game.c \
			exec_mon_gars/mlx.c \
			exec_mon_gars/movements.c\
			exec_mon_gars/init.c \
			exec_mon_gars/camera.c \
			exec_mon_gars/doors.c \
			exec_mon_gars/minimap.c \

SRCS		:= $(SRCS:%=$(SRC_DIR)/%)
OBJS		:= $(SRCS:.c=.o)
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -o3
RM			:= rm -f
MAKEFLAGS	+= --no-print-directory
DIR_DUP		= mkdir -p $(@D)
LIBRARIES	:= -L libft -lft -L ./mlx -lmlx -lXext -lX11 -lm -lbsd
INCLUDES	:= -Ilibft/include -I ./inc -I ./libft -I ./mlx -I include
OBJS_BONUS	:= $(SRCS:.c=_bonus.o)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -DBONUS=0 -c $< -o $@

%_bonus.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -DBONUS=1 -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./mlx
	$(MAKE) -C ./libft
	$(CC) $(OBJS) $(LIBRARIES) -o $(NAME)
	$(info CREATED $@)

bonus:$(OBJS_BONUS)
	$(MAKE) -C ./mlx
	$(MAKE) -C ./libft
	$(CC) $(OBJS_BONUS) $(LIBRARIES) -o $(NAME)_bonus
	$(info CREATED $@)

debug:
	$(MAKE) -C ./mlx
	$(MAKE) -C ./libft
	cc $(CFLAGS) $(INCLUDES) -g -o $(NAME) $(SRCS) $(LIBRARIES) -fsanitize=address

debug_bonus:
	$(MAKE) -C ./mlx
	$(MAKE) -C ./libft
	cc $(CFLAGS) $(INCLUDES) -DBONUS=1 -g -o $(NAME)_bonus $(SRCS) $(LIBRARIES) -fsanitize=address

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME) $(NAME)_bonus
	$(MAKE) fclean -C ./libft
	$(MAKE) clean -C ./mlx

re: fclean all

.PHONY: clean fclean re