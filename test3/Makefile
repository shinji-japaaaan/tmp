# ************************************************************************************ #
#                                                                                      #
#                                                                 :::      ::::::::    #
#    Makefile                                                   :+:      :+:    :+:    #
#                                                             +:+ +:+         +:+      #
#    By: sishizaw <sishizaw@student.42.fr>                  +#+  +:+       +#+         #
#                                                         +#+#+#+#+#+   +#+            #
#    Created: 2024/08/10 12:31:50 by sishizaw                  #+#    #+#              #
#    Updated: 2024/08/10 12:32:37 by sishizaw                 ###   ########.fr        #
#                                                                                      #
# ************************************************************************************ #

NAME = push_swap
CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
LIBFTDIR = libft/
OBJ_DIR = obj/
SRC_DIR = srcs/

SRC_1 = srcs/main.c \

SRC_2 =	srcs/sort.c \
		srcs/operations_1.c \
		srcs/operations_2.c \
		srcs/operations_3.c \
		srcs/utils_apply.c \
		srcs/utils_case_ab.c \
		srcs/utils_case_ba.c \
		srcs/utils_check.c \
		srcs/utils_find.c \
		srcs/utils_input.c \
		srcs/utils_libft1.c \
		srcs/utils_libft2.c \
		srcs/utils_other.c \
		srcs/utils_get_costinfo.c \

OBJ_1 = ${SRC_1:.c=.o}
OBJ_2 = ${SRC_2:.c=.o}

INCLUDE = -L ./libft -lft

.c.o:
	${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ_1} ${OBJ_2}
	make -C $(LIBFTDIR)
	${CC} ${FLAGS} ${OBJ_1} ${OBJ_2} -o ${NAME} ${INCLUDE}

${BONUS}: ${OBJ_2} 
	make -C $(LIBFTDIR)
	${CC} ${FLAGS} ${OBJ_2} -o ${INCLUDE}

all: ${NAME}

clean:
	${RM} ${OBJ_1} ${OBJ_2} ${NAME}
	@cd $(LIBFTDIR) && $(MAKE) clean

fclean: clean
	${RM} ${NAME}
	@cd $(LIBFTDIR) && $(MAKE) fclean

re: clean all

.PHONY: all clean fclean re bonus