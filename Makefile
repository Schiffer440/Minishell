# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adugain <adugain@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/19 21:41:34 by adugain           #+#    #+#              #
#    Updated: 2023/12/25 13:10:33 by adugain          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Minishell

LIBFT = libft/libft.a

SRC = files/main.c \
files/free.c \
files/init.c \
files/cmd.c \
builtin/builtin.c \
files/ft_2d_arrays.c \
files/ft_str_utils.c

CFLAGS	= -Wextra -Wall -Werror -MMD -g3 -O2

CC = cc

OBJ_DIR = ./objs/

OBJ = $(SRC:.c=.o)

OBJ := $(addprefix $(OBJ_DIR), $(OBJ))

DEP := $(OBJ:.o=.d)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) -lreadline

$(LIBFT) :
	make -C ./libft
clean:
	rm -rf $(OBJ_DIR)
	make fclean -C ./libft

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

$(OBJ_DIR)%.o : %.c
	@mkdir -p $(@D)
	${CC} ${CFLAGS} -c $< -o $@

-include $(DEP)