# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: root <root@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/23 13:48:18 by yogun             #+#    #+#              #
#    Updated: 2024/08/04 13:48:37 by root             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
LIBFTDIR = libft/
OBJ_DIR = obj/
SRC_DIR = srcs/

SRC_1 = srcs/main.c \

SRC_2 =	srcs/algorithm.c \
		srcs/add_back.c \
		srcs/stack_new.c \
		srcs/solver_utils_ab.c \
		srcs/solver_utils_ba.c \
		srcs/rotate_and_push.c \
		srcs/operations.c \
		srcs/operations_2.c \
		srcs/operations_3.c \
		srcs/check_dup.c \
		srcs/check_sorted.c \
		srcs/error_print.c \
		srcs/free.c \
		srcs/lst_utils.c \
		srcs/lst_utils_2.c \
		srcs/rotate_type.c \
		srcs/sort_three.c \
		srcs/sort_big.c \

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