# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/28 15:02:52 by tzi-qi            #+#    #+#              #
#    Updated: 2022/08/28 17:00:42 by tzi-qi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = $(addsuffix .c, main)

OBJS = $(SRCS:%.c=%.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Imlx

RM = rm -r

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
