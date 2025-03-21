/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiz-dos <luiz-dos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:08:02 by shulte            #+#    #+#             */
/*   Updated: 2025/01/14 14:41:32 by luiz-dos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBS_H
# define LIBS_H

# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h> // to use the LONG_MAX and LONG_MIN macros
# include <sys/types.h> // to use the MACRO WIFEXITED
# include <sys/wait.h> // to use the MACRO UNTRACED
# include <signal.h> // to use the signal function
# include <errno.h> // to use the errno variable
# include <string.h> // to use the strerror function
# include <fcntl.h> // to use the open function
# include <sys/stat.h> // to use the stat function
# include <dirent.h> // to use the opendir function
# include <termios.h> // to use the termios struct
// # include "enums.h" // to include enums in the project
# include "functions.h" // to include functions in the project
# include "structs.h" // to include structures in the project
# include "../libft/inc/libft.h" // to include the libft library
# include <stdarg.h> // to use the va_list type to ft_error_msg_construct

# define CYAN "\033[1;36m"
# define RESET "\033[0m"

//extern volatile sig_atomic_t	g_sig;
extern int	global_sig;

#endif