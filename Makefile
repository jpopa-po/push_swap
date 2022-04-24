# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpopa-po <jpopa-po@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/26 11:58:16 by cmarcu            #+#    #+#              #
#    Updated: 2022/04/24 14:35:22 by jpopa-po         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = push_swap.c rule_swap.c rule_push.c rule_rotate.c \
		error_checking.c sorter.c chunker.c ruler.c utils.c

SRCS_BONUS = rule_swap.c rule_push.c rule_rotate.c utils.c \
		error_checking.c checker.c ruler.c

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

NAME = push_swap

LIBFTPATH	= libft/
CC = gcc
CFLAGS = -Werror -Wextra -Wall -g3 -fsanitize=address
RM = rm -f

INCLUDES = includes/

all: $(NAME)

$(NAME):
	make -sC ${LIBFTPATH}
	cp ./libft/libft.a .
	${CC} ${CFLAGS} libft.a ${SRCS} -I ${INCLUDES} -o ${NAME}

bonus: $(OBJS_BONUS)
	@$(CC) $(LDFLAGS) $(OBJS_BONUS) -I $(INCLUDES) -o checker

ARG :=	$(shell seq 0 499 | sort -R)

exe: $(NAME)
	./push_swap $(ARG)

check: $(NAME)
	./push_swap $(ARG) | ./checker_Mac $(ARG)

check_bonus: $(NAME) bonus
	@echo Official checker
	./push_swap $(ARG) | ./checker_Mac $(ARG)
	@echo My checker
	./push_swap $(ARG) | ./checker $(ARG)

clean:
		$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
		make -sC ${LIBFTPATH} fclean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
