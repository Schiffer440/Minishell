# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbruyant <mbruyant@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/26 15:18:53 by mbruyant          #+#    #+#              #
#    Updated: 2023/10/30 23:21:44 by mbruyant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror -O2 -g
LIBFTFLAGS = my_libft/libft.a
SOURCES = srcs/main.c \
srcs/child.c \
srcs/utils.c \
srcs/init.c \
srcs/parsing.c \
srcs/wait.c
OBJS = ${SOURCES:.c=.o}
INC = includes/pipex.h

all: ${NAME}

${NAME}: ${INC} ${OBJS} ${SOURCES}
	${MAKE} -C my_libft
	@echo "\033[0;32;1mCompilation libft & GNL OK\033[0m"
	${CC} ${CFLAGS} ${SOURCES} -o ${NAME} -include ${INC} ${LIBFTFLAGS} 

clean :
	${MAKE} -C my_libft clean
	${RM} ${OBJS}
	@echo "\033[0;31;1mClean OK\033[0m"

fclean : clean
	${MAKE} -C my_libft fclean
	${RM} ${NAME}
	@echo "\033[0;31;1mfclean OK\033[0m"

re : fclean all

.PHONY : all fclean clean re
