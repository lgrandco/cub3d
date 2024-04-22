# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eghaffar <eghaffar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/08 11:49:02 by eghaffar          #+#    #+#              #
#    Updated: 2024/04/21 15:56:49 by eghaffar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := libft.a
SRC_DIR     := .
BUILD_DIR   := .build
SRCS		:= \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isascii.c \
			ft_isalnum.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_atoi.c	\
			ft_calloc.c \
			ft_strdup.c \
			ft_bzero.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memset.c \
			ft_memset.c\
			ft_strchr.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strncmp.c\
			ft_strnstr.c\
			ft_split.c\
			ft_striteri.c\
			ft_strmapi.c\
			ft_strnstr.c\
			ft_strrchr.c\
			ft_substr.c\
			ft_strtrim.c \
			get_next_line.c \
			get_next_line_utils.c 

SRCS		:= $(SRCS:%=$(SRC_DIR)/%)
OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS		:= $(OBJS:.o=.d)

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g3
CPPFLAGS	:= -MMD -MP -I include
AR			:= ar
ARFLAGS		:= -r -c -s
RM			:= rm -f
MAKEFLAGS	+= --no-print-directory
DIR_DUP		= mkdir -p $(@D)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	$(info CREATED $@)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	$(info CREATED $@)

-include $(DEPS)

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: clean fclean re
.SILENT: