# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shulte <shulte@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/18 17:37:50 by ncampbel          #+#    #+#              #
#    Updated: 2025/01/22 13:50:45 by shulte           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minishell
CC		= cc
CFLAGS 	= -Wall -Wextra -Werror -g
RM		= rm -f

# Directories
SRC_DIR = src/
OBJ_DIR = obj/
PRS_DIR = obj_parse/

# Libraries
LIBFT_DIR	= libft/
LIBFT		= $(LIBFT_DIR)libft.a
LIBS		= -lreadline

# Source files
SRCS	=	$(SRC_DIR)cd.c \
			$(SRC_DIR)check_envp.c \
			$(SRC_DIR)copy_envp.c \
			$(SRC_DIR)dolar.c \
			$(SRC_DIR)echo.c \
			$(SRC_DIR)env.c \
			$(SRC_DIR)execute_command.c \
			$(SRC_DIR)export.c \
			$(SRC_DIR)finders.c \
			$(SRC_DIR)ft_free.c \
			$(SRC_DIR)ft_strcat.c \
			$(SRC_DIR)ft_strcmp.c \
			$(SRC_DIR)ft_strcpy.c \
			$(SRC_DIR)ft_strdup_two.c \
			$(SRC_DIR)ft_strjoin_free.c \
			$(SRC_DIR)main.c \
			$(SRC_DIR)prompt.c \
			$(SRC_DIR)pwd.c \
			$(SRC_DIR)redirection.c \
			$(SRC_DIR)set_envvar.c \
			$(SRC_DIR)teste.c \
			$(SRC_DIR)unset.c \
			$(SRC_DIR)utils.c \
			$(SRC_DIR)clear.c \
			$(SRC_DIR)input_analizes.c \
			$(SRC_DIR)quote_checker.c \
			$(SRC_DIR)quote_handle.c \
			$(SRC_DIR)split_token.c \
			$(SRC_DIR)tokenization.c
			
OBJS	= $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(LIBS)

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