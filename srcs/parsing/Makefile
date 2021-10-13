# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/31 08:51:26 by mmondell          #+#    #+#              #
#    Updated: 2021/10/12 18:34:34 by mmondell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#*#######################################################
##*          ERASE COMMENTS FOR BONUS PARTS            ##
#*#######################################################

## -----  NAME OF THE PROGRAMM ----- ##
NAME 			=	parse

## ----- NAME OF THE BONUS PART ----- ##
#*B_NAME			= 

## ----- CHOOSE COMPILER AND FLAGS ----- ##
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror -g

## ----- PATH TO FOLDERS ----- ##
SRCS_DIR		=	srcs/
#*B_SRCS_DIR		= 

OBJ_DIR			=	obj/

INCLUDE_DIR		=	../../includes/

LIBFT_DIR		=	../../libft/

## ----- SOURCE FILES ----- ##
SRCS_FILES		= 	parse_input.c parse_utils.c token_lst_utils.c token_utils.c\
					tokens.c syntax.c ../errors.c main_tester.c
## ----- BONUS SOURCE FILES ----- ##
#*B_SRCS_FILES	= 

## ----- .C TO .O CONVERT ----- ##
OBJ_FILES		=	$(SRCS_FILES:.c=.o)
#*B_OBJ_FILES		= $(B_SRCS_FILES:.c=.o)

## ----- ADDPREFIX TO FILES ----- ##
# MAIN PROGRAMM #
SRCS			=	$(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJS			=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))
VPATH			=	$(SRCS_DIR) #$(B_SRCS_DIR)

# BONUS PART #
#*B_SRCS			= $(addprefix $(B_SRCS_DIR), $(B_SRCS_FILES))
#*B_OBJS			= $(addprefix $(OBJ_DIR), $(B_OBJ_FILES))

#--------------------------------------------------------------#

## ----- TOOLS AND COLORS ----- ##
RM				=	rm -Rf
NO_PRINT		=	--no-print-directory
RED 			=	\033[31m
GREEN 			=	\033[32m
YELLOW 			=	\033[33m
BLUE 			=	\033[34m
PINK 			=	\033[35m
AQUA 			=	\033[36m
GREY 			=	\033[37m
UNDERLINE 		=	\033[4m
NORMAL 			=	\033[0m

LIBFT			=	$(MAKE) bonus -C $(LIBFT_DIR)

## ----- ALL ACTION DEPENDENCIES AND RECIPE FOR MAIN PROGRAM ----- ##
all: obj $(NAME)
	@echo "$(GREEN)Compilation Completed Successfully$(NORMAL)"

$(OBJ_DIR)%.o:%.c
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(INCLUDE_DIR) -o $@ -c $<

$(NAME): $(OBJS)
	$(LIBFT)
	$(CC) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

linux :	obj $(OBJS_PATH) $(OBJS)
	@$(LIBFT)
	@$(CC) $(OBJS) -L$(LIBFT_PATH) -l$(LIBFT) -lcurses -lreadline -o $(NAME)
	@echo "\\n\033[32;1m Compilation Complete \033[0m \\n"

obj:
	@mkdir -p $(OBJ_DIR)

## ----- ACTIONS FOR THE BONUS PART ----- ##
#*bonus: $(B_NAME)
#*	@echo "$(GREEN)Bonus Files Compiled!$(NORMAL)"
#*
#*$(B_NAME): $(B_OBJS)
#*	$(LIBFT)
#*	$(CC) $(B_OBJS) -L$(LIBFT_DIR) -lft -o $(B_NAME)

## ----- CLEAN COMMANDS ----- ##
clean:
	@$(RM) $(OBJS) $(B_OBJS)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@$(RM) $(NAME) $(OBJ_DIR)
#*	$(RM) $(B_NAME) $(OBJ_DIR)
	@make -C $(LIBFT_DIR) fclean

re: fclean all #bonus

.PHONY: all clean fclean re
