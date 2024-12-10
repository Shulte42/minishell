NAME	= mini
SRCS	= ${wildcard *.c}
OBJS	= ${SRCS:.c=.o}
LIBFT	= libft

all: ${NAME}

${NAME}: ${OBJS}
	make -C ${LIBFT}
	cc ${OBJS} -L${LIBFT} -lreadline -lft -o $@

%.o: %.c
	cc -c $< -o $@

clean:
	make clean -C ${LIBFT}
	rm -f ${OBJS}

fclean: clean
	make fclean -C ${LIBFT}
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
