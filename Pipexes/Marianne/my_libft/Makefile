NAME = libft.a

CC = cc
FLAGS = -Wall -Werror -Wextra
INC = libft.h
SRCS = ft_2d_arrays.c \
ft_ai_to_ia.c \
ft_calloc.c \
ft_char_is.c \
ft_char_mod.c \
ft_lst_one.c \
ft_lst_two.c \
ft_mem.c \
ft_put_fd.c \
ft_scan_str.c \
ft_split_append.c \
ft_split.c \
ft_str_dup.c \
ft_str_is.c \
ft_str_l.c \
ft_strlen.c \
ft_str_misc.c \
ft_str_mod.c \
ft_str_n.c \
get_next_line.c

OBJS = ${SRCS:.c=.o}

all : ${NAME}

${NAME} : ${OBJS} ${INC} ${SRCS}
	${CC} ${FLAGS} -c ${SRCS} -include ${INC}
	ar rc $@ ${OBJS}

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY : all fclean clean re