# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/06 13:35:06 by tzi-qi            #+#    #+#              #
#    Updated: 2022/09/16 21:28:34 by tzi-qi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

# MANDATORY
SRC_DIR = ./
SRC = $(addprefix $(SRC_DIR)ft_, $(addsuffix .c, \
		isalpha isdigit isalnum isascii isprint toupper tolower \
		memset memcpy memmove memchr memcmp atoi bzero calloc\
		strlen strlcpy strlcat strncmp strchr strrchr strnstr strdup \
		substr strjoin strtrim split itoa strmapi striteri \
		putchar_fd putstr_fd putendl_fd putnbr_fd))
OBJ = $(SRC:%.c=%.o)

# BONUS
B_SRC = $(addprefix $(SRC_DIR)ft_, $(addsuffix .c, \
		lstnew lstadd_front lstsize lstlast lstadd_back lstdelone \
		lstclear lstiter lstmap))
B_OBJ = $(B_SRC:%.c=%.o)

# HEADER
INC = ./
HEAD = -I $(INC)

# COMPILER
#-L ../libft -l ft<-- make the lib file dir able to be accessed anywhere
CC = gcc
CFLAGS = -Wall -Werror -Wextra $(HEAD)

# LIBRARY
LIBCR = ar -rcs

# REMOVE FILES
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ) $(B_OBJ)
	@$(LIBCR) $(NAME) $(OBJ) $(B_OBJ)

# %.o: %.c
# 	$(CC) $(CFLAG) -c $< -o $@
man: $(OBJ)
	@$(LIBCR) $(NAME) $(OBJ)

bonus: $(B_OBJ)
	@$(LIBCR) $(NAME) $(B_OBJ)
	
clean:
	@$(RM) $(OBJ) ${B_OBJ}

fclean: clean
	@$(RM) $(NAME)

re: fclean all

norme:
	norminette -R CheckForbiddenSourceHeader $(SRC) $(B_SRC) ./libft.h

.PHONY: all clean fclean re norme bonus