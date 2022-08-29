# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dantavar <dantavar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/03 14:24:59 by dantavar          #+#    #+#              #
#    Updated: 2022/08/10 00:17:00 by dantavar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc
CFLAGS = -Wall -Wextra -Werror

FUNC_DIR = func/
FUNC_SRCS = ft_split.c ft_strdup.c ft_strjoin.c ft_strlen.c ft_strncmp.c
FUNC = $(addprefix $(FUNC_DIR), $(FUNC_SRCS))
OBJS_F = $(FUNC:.c=.o)

SRCS =  childs.c pipex.c
OBJS_M = $(SRCS:.c=.o)

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS_F) $(OBJS_M)
	@$(CC) $(OBJS_F) $(OBJS_M) -o $(NAME)

clean:
	$(RM) $(OBJS_M) $(OBJS_F) $(OBJS_B)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re fclean clean