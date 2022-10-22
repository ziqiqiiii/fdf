# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/28 15:02:52 by tzi-qi            #+#    #+#              #
#    Updated: 2022/10/22 14:41:21 by tzi-qi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fdf

CC			= gcc
CCD			= gcc -fsanitize=address
CFLAGS		= -Wall -Wextra -Werror -D BUFFER_SIZE=100
MLX			= -lmlx -framework OpenGL -framework AppKit

RM 			= rm -r

SRC_DIR	 	= ./
OBJ_DIR		= ./obj
GNL_DIR		= ./get_next_line

SRCS		= main.c parsing.c initialise.c algorithm.c
OBJS		= $(SRCS:%.c=$(OBJ_DIR)/%.o)

GNL_SRCS	= get_next_line.c get_next_line_utils.c
GNL_OBJ		= $(GNL_SRCS:%.c=$(OBJ_DIR)/%.o)

INCLUDES	= -Iincludes -Ilibft -Iget_next_line -Imlx
LIB			= -Llibft -lft

# -Llibft 
# -lft

all: $(NAME)

$(NAME): $(OBJS) $(GNL_OBJ) libft/libft.a
		$(CCD) $(CFLAGS) $(OBJS) $(GNL_OBJ) $(INCLUDES) $(LIB) $(MLX) -o $@

libft/libft.a:
	@make all -C libft

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		@mkdir -p $(OBJ_DIR)
		@$(CC) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(GNL_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

test:
	make && ./fdf ./maps/elem2.fdf

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)
	@make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
