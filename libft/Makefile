# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/17 14:02:25 by mafortin          #+#    #+#              #
#    Updated: 2021/10/12 17:04:23 by mafortin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= libft.a
SRCS 	= ft_isalnum.c ft_isdigit.c ft_memccpy.c ft_memcpy.c ft_putchar_fd.c\
		ft_putstr_fd.c ft_strdup.c ft_strlcpy.c ft_strncmp.c ft_strtrim.c\
		ft_toupper.c ft_bzero.c ft_isalpha.c ft_isprint.c ft_memchr.c\
		ft_memmove.c ft_putendl_fd.c ft_split.c ft_strjoin.c ft_strlen.c\
		ft_strnstr.c ft_substr.c ft_atoi.c ft_calloc.c ft_isascii.c ft_itoa.c\
		ft_memcmp.c ft_memset.c ft_putnbr_fd.c ft_strchr.c ft_strlcat.c\
		ft_strmapi.c ft_strrchr.c ft_tolower.c ft_digit_len.c ft_utoa.c\
		ft_inv_string.c ft_itoa_hex.c ft_free_tab.c ft_lstnew.c ft_lstadd_front.c\
		ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c\
		ft_lstiter.c ft_lstmap.c ft_lst_return_int.c ft_atol.c ft_lstnew.c \
		ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
		ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_matrice_size.c ft_isdigit_s.c\
		ft_isdigit_string.c get_next_line.c get_next_line_utils.c ft_char_search.c\
		ft_change_line.c ft_print_matrice.c ft_matrice_cpy.c ft_addline.c\
		ft_print_matrice_fd.c ft_majchar.c ft_strndup.c ft_remove_line.c\
		ft_append_string.c
OBJS 	= ${SRCS:.c=.o}
OBJS_B	= ${SRCS_B:.c=.o}
HEADER	= libft.h

CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror

.c.o:		%.o : %.c libft.h
					${CC} ${CFLAGS} -I "." -c $< -o $(<:.c=.o)

$(NAME):	${OBJS}
					ar rc ${NAME} ${OBJS}

all: 		${NAME}

bonus:		${OBJS} ${OBJS_B}
					ar rc ${NAME} ${OBJS} ${OBJS_B}

clean:
					rm -f ${OBJS} ${OBJS_B}

fclean: 	clean
					rm -f $(NAME)

re:			fclean all

.PHONY: all clean fclean re bonus