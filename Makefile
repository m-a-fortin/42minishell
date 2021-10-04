# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/22 11:49:47 by mafortin          #+#    #+#              #
#    Updated: 2021/10/04 15:52:16 by mafortin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME =		minishell
OBJS_PATH =	objs
SRCS_PATH =	srcs
#EXEC_PATH = srcs/exec
LIBFT =		libft
LIB =		lib

SRCS =		minishell.c ms_signals.c ms_envp_utils.c ms_export.c\
ms_exec_error.c
#EXEC =		ms_pwd_echo_env.c ms_cd.c ms_export.c ms_exec_error.c
CC =		gcc
CFLAGS =	-Wall -Werror -Wextra -c -g
INCLUDES =	-Imlx_mac -Iincludes
OBJS =		$(SRCS:.c=.o)

SRCS_FULL 	=	$(addprefix srcs/, $(SRCS))
OBJS_FULL 	=	$(addprefix objs/, $(OBJS))

all: $(OBJS_PATH) $(NAME)

$(OBJS_PATH):
	@mkdir -p $(OBJS_PATH)
	@echo Created: Object directory

$(NAME): $(OBJS_FULL)
	@make re --no-print-directory -C ./libft
	@$(CC) $(OBJS_FULL) -L$(LIB) -Llibft -lft -lreadline -lcurses -o $(NAME)
	@echo "\\n\033[32;1m MINISHELL IS READY \033[0m \\n"

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c
	@echo "Created: $@\033[1A\033[M"
	@$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	@make clean --no-print-directory -C ./libft
	@rm -rf $(OBJS_FULL) $(OBJS_PATH) 
	@echo "\033[34;1m CLEAN DONE \033[0m"

fclean: clean
	@make fclean --no-print-directory -C ./libft
	@rm -f $(NAME)
	@echo "\033[34;1m FCLEAN DONE \033[0m"

re: fclean all

.PHONY: all clean fclean re
