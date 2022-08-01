# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/07 18:31:06 by flcarval          #+#    #+#              #
#    Updated: 2022/08/01 15:18:15 by tbrebion         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lib42.a
MANDATORY = $(addprefix src/ft_, atoi.c bzero.c calloc.c isalnum.c\
isalpha.c isascii.c isdigit.c isprint.c itoa.c memchr.c memcmp.c\
memcpy.c memmove.c memset.c putchar_fd.c putendl_fd.c putnbr_fd.c\
putstr_fd.c split.c strchr.c strdup.c striteri.c strjoin.c strlcat.c\
strlcpy.c strlen.c strmapi.c strncmp.c strnstr.c strrchr.c strtrim.c\
substr.c tolower.c toupper.c)
BONUSES = $(addprefix src/ft_, lstadd_back.c lstadd_front.c lstclear.c\
lstdelone.c lstiter.c lstlast.c lstmap.c lstnew.c lstsize.c)
GNL = $(addprefix src/get_next_, line.c line_utils.c)
OBJ_M = ${MANDATORY:.c=.o}
OBJ_B = ${BONUSES:.c=.o}
OBJ_GNL = ${GNL:.c=.o}
OBJ = $(OBJ_GNL) $(OBJ_B) $(OBJ_M)
CC = gcc
FLAGS = -Wall -Werror -Wextra

all: $(NAME) clean

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

