# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/22 11:49:47 by mafortin          #+#    #+#              #
#    Updated: 2021/10/29 19:40:40 by mmondell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	minishell

INC_PATH	=	includes/
OBJS_PATH 	=	objs/
SRCS_PATH 	=	srcs/
LIB_PATH 	=	lib/
CC 			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
RM			=	rm -rf

LIBFT_PATH	=	libft/
LIBFT		=	ft

INC_FILES 	=	minishell.h token.h parse.h exec.h shell_errors.h

SRCS_FILES	=	minishell.c ms_signals.c ms_envp_utils.c errors.c ms_job_utils.c

EXEC_FILES	=	ms_cd.c ms_export.c ms_pwd_echo_env.c ms_unset.c ms_exec.c\
				ms_exit.c ms_exec_utils.c ms_exec_error.c ms_redirection.c\
				ms_exec_fork.c ms_exec_fork_utils.c ms_pipe.c ms_pipe_utils.c\
				ms_fork_error.c
				
PARSE_FILES	=	parse_input.c parse_utils.c token_lst_utils.c token_utils.c\
				tokens.c syntax.c dollar_sign.c dollar_sign_utils.c build_job.c\
				build_utils.c trim_quotes.c hdoc_utils.c build_hdoc.c

MAKELIBFT	=	$(MAKE) --no-print-directory -C $(LIBFT_PATH)

EXEC_PATH	= 	$(SRCS_PATH)exec
PARSE_PATH	=	$(SRCS_PATH)parsing

SRCS 		=	$(addprefix $(SRCS_PATH), $(SRCS_FILES))
PARSE_SRCS	=	$(addprefix $(PARSE_PATH), $(PARSE_FILES))
EXEC_SRCS	= 	$(addprefix $(EXEC_PATH), $(EXEC_FILES))

OBJS_FILES	= 	$(SRCS_FILES:.c=.o) $(PARSE_FILES:.c=.o) $(EXEC_FILES:.c=.o)

INCLUDES	=	$(addprefix $(INC_PATH), $(INC_FILES))
OBJS 		=	$(addprefix $(OBJS_PATH), $(OBJS_FILES))

VPATH		=	$(SRCS_PATH) $(PARSE_PATH) $(EXEC_PATH)

$(OBJS_PATH)%.o: %.c
	@$(CC) $(CFLAGS) -I$(INC_PATH) -I$(LIBFT_PATH) -c $< -o $@

all:	CFLAGS += -O2
all:	$(NAME)

$(NAME):	$(OBJS_PATH) $(OBJS)
	@echo "\n\033[96m Compiling MINISHELL \033[0m\n"
	@$(MAKELIBFT)
	$(CC) $(OBJS) -L$(LIBFT_PATH) -l$(LIBFT) -L$(LIB_PATH) -lreadline -lcurses -o $(NAME)
	@echo "\\n\033[32;1m MINISHELL IS READY \033[0m \\n"

$(OBJS_PATH):
	@mkdir -p $(OBJS_PATH)
	@echo "\033[34;1m Created Object Directory \033[0m"

linux : CFLAGS += -g
linux :	$(OBJS_PATH) $(OBJS)
	@echo "\033[95m Compiling MINISHELL \033[0m"
	$(MAKELIBFT)
	$(CC) $(OBJS) -L$(LIBFT_PATH) -l$(LIBFT) -lcurses -lreadline -o $(NAME)
	@echo "\\n\033[32;1m MINISHELL IS READY \033[0m \\n"

debug:	CFLAGS += -g
debug:	$(NAME)

clean:
	@make clean --no-print-directory -C ./libft
	@$(RM) $(OBJS_FILES) $(OBJS_PATH) 
	@echo "\033[34;1m CLEAN DONE \033[0m"

fclean: clean
	@make fclean --no-print-directory -C ./libft
	@$(RM) $(NAME)
	@echo "\033[34;1m FCLEAN DONE \033[0m"

re: fclean all

.PHONY: all clean fclean re
