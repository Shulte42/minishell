# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shulte <shulte@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/18 17:37:50 by ncampbel          #+#    #+#              #
#    Updated: 2025/01/08 14:27:49 by shulte           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	teste_parse
CC		=	cc
CFLAGS 	= 	-Wall -Wextra -Werror -g -Iinc
RM		=	rm -f
# Directories
SRC_DIR = src/
OBJ_DIR = obj/

# Libraries
LIBFT_DIR	=	libft/
LIBFT	=	$(LIBFT_DIR)libft.a
LIBS = -lreadline

# Include directory
INC = inc/

# Source files
SRCS	=	$(SRC_DIR)input_analizes.c \
			$(SRC_DIR)parse.c \
			$(SRC_DIR)envvar.c \
			$(SRC_DIR)tokenization.c \
			$(SRC_DIR)quote_checker.c

OBJS	=	$(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

all: $(NAME)


$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) $(LIBFT) $(LIBS)


$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) -r $(OBJ_DIR)
	@$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
		@$(RM) $(NAME)
		@$(RM) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re