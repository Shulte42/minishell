NAME	= mini
SRCS	= ${wildcard *.c}
OBJDIR	= obj
OBJS	= ${SRCS:%.c=${OBJDIR}/%.o}
LIBFT	= libft

all: ${NAME}

${NAME}: ${OBJS}
	make -C ${LIBFT}
	cc ${OBJS} -L${LIBFT} -lreadline -lft -o $@

${OBJDIR}/%.o: %.c | ${OBJDIR}
	cc -c $< -o $@

${OBJDIR}:
	mkdir -p ${OBJDIR}

clean:
	make clean -C ${LIBFT}
	rm -rf ${OBJDIR}

fclean: clean
	make fclean -C ${LIBFT}
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
