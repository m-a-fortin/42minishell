# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/22 11:49:47 by mafortin          #+#    #+#              #
#    Updated: 2021/10/05 08:14:11 by mmondell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	minishell

INC_PATH	=	includes/
OBJS_PATH 	=	objs/
SRCS_PATH 	=	srcs/
LIB_PATH 	=	lib/
CC 			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -c -g
RM			=	rm -rf

INC_FILES 	=	minishell.h token.h parse.h exec.h
SRCS_FILES	=	minishell.c ms_signals.c ms_pwd_echo_env.c ms_envp_utils.c #ms_cd.c

#LIBS 		=	-Llibft -lft -lreadline -lcurses
OBJS 		=	$(SRCS:.c=.o)

SRCS 		=	$(addprefix srcs/, $(SRCS))
OBJS 		=	$(addprefix objs/, $(OBJS))

all: $(OBJS_PATH) $(NAME)

$(OBJS_PATH):
	@mkdir -p $(OBJS_PATH)
	@echo Created: Object directory

$(NAME): $(OBJS_FILES)
	@make re --no-print-directory -C ./libft
	@$(CC) $(OBJS_FILES) -L$(LIB) -Llibft -lft -lreadline -lcurses -o $(NAME)
	@echo "\\n\033[32;1m MINISHELL IS READY \033[0m \\n"

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c
	@echo "Created: $@\033[1A\033[M"
	@$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	@make clean --no-print-directory -C ./libft
	@rm -rf $(OBJS_FILES) $(OBJS_PATH) 
	@echo "\033[34;1m CLEAN DONE \033[0m"

fclean: clean
	@make fclean --no-print-directory -C ./libft
	@rm -f $(NAME)
	@echo "\033[34;1m FCLEAN DONE \033[0m"

re: fclean all

.PHONY: all clean fclean re
