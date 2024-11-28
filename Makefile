NAME	= mini
SRCS	= ${wildcard *.c}
OBJS	= ${SRCS:.c=.o}
LIBFT	= libft

all: ${NAME}

${NAME}: ${OBJS}
	make -C ${LIBFT}
	cc ${OBJS} -L${LIBFT} -lft -o $@

%.o: %.c
	cc -c $< -o $@

clean:
	make clean -C ${LIBFT}
	rm ${OBJS}

fclean: clean
	make fclean -C ${LIBFT}
	rm ${NAME}

re: fclean all

.PHONY: all clean fclean re
