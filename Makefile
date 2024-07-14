# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/14 14:54:32 by jroulet           #+#    #+#              #
#    Updated: 2024/07/14 16:10:46 by jroulet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -L./mlx_linux -lmlx -Ilmlx -lXext -lX11
HEADER = -I./header
LIBFT = ./libft/libft.a
GNL = ./GNL/get_next_line.a  # Adjusted to get_next_line.a
VPATH = src error
RM = rm -rf
NAME = so_long

ERROR = error
SRC = action_key check_map create_map map_validator mlx update draw_map

SRCS = $(addsuffix .c, $(ERROR)) $(addsuffix .c, $(SRC)) main.c

OBJ_DIR = obj
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS) $(LIBFT) $(GNL)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(GNL) $(MLXFLAGS) -o $(NAME)

$(OBJ_DIR):
	mkdir -p obj

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(HEADER)

$(LIBFT):
	$(MAKE) -C ./libft

$(GNL):
	$(MAKE) -C ./GNL

clean:
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./GNL
	$(RM) $(OBJ_DIR)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(MAKE) fclean -C ./GNL
	$(RM) $(NAME)

re: fclean all
