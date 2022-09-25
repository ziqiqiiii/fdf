# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/28 15:02:52 by tzi-qi            #+#    #+#              #
#    Updated: 2022/09/25 17:44:55 by tzi-qi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fdf

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -D BUFFER_SIZE=1
MLX			= -lmlx -framework OpenGL -framework AppKit

RM 			= rm -r

SRC_DIR	 	= ./
OBJ_DIR		= ./obj
GNL_DIR		= ./get_next_line

SRCS		= main.c parsing.c
OBJS		= $(SRCS:%.c=$(OBJ_DIR)/%.o)

GNL_SRCS	= get_next_line.c get_next_line_utils.c
GNL_OBJ		= $(GNL_SRCS:%.c=$(OBJ_DIR)/%.o)

INCLUDES	= -Iincludes -Ilibft -Iget_next_line -Imlx
LIB			= -Llibft -lft

# -Llibft 
# -lft

all: $(NAME)

$(NAME): $(OBJS) $(GNL_OBJ) libft/libft.a
		$(CC) $(CFLAGS) $(OBJS) $(GNL_OBJ) $(INCLUDES) $(LIB) $(MLX) -o $@

libft/libft.a:
	@make all -C libft

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		@mkdir -p $(OBJ_DIR)
		@$(CC) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(GNL_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

test:
	make && ./fdf ./maps/elem.fdf

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)
	@make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
