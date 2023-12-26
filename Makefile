# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbruyant <mbruyant@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/19 21:41:34 by adugain           #+#    #+#              #
#    Updated: 2023/12/26 12:18:09 by mbruyant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Minishell

LIBFT = libft/libft.a

SRC = files/main.c \
files/free.c \
files/init.c \
files/cmd.c \
builtin/builtin.c \
utils/ft_2d_arrays.c \
utils/ft_str_utils.c \
utils/ft_printf_fd/srcs/ft_printf.c \
utils/ft_printf_fd/srcs/ft_printf_hex.c \
utils/ft_printf_fd/srcs/ft_printf_fun.c \
utils/ft_printf_fd/srcs/ft_printf_nb.c \
utils/ft_printf_fd/srcs/ft_printf_ptr.c \
utils/ft_printf_fd/srcs/ft_printf_uns.c

CFLAGS	= -Wextra -Wall -Werror -MMD -g3 -O1

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