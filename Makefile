# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eelhafia <eelhafia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/13 18:34:16 by eelhafia          #+#    #+#              #
#    Updated: 2023/02/26 18:21:56 by eelhafia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
RM = rm -f
AR = ar rc
CC = cc -Wall -Wextra -Werror 
NAME1 = push_swap
NB    = bonus.a
checker = checker

SRC = push_swap.c swap_all.c linked_list_op.c oper_stk.c function_help.c \
	  function_help_1.c function_check.c  functions.c

B_SRC = get_next_line.c get_next_line_utils.c  push_swap.c checker.c \
		oper_stk.c swap_all.c function_check.c functions.c function_help.c \
		function_help_1.c linked_list_op.c

LIBFT = libft.a

OBJ = $(SRC:.c=.o)

B_OBJ = $(B_SRC:.c=.o)

all : $(NAME) $(NAME1)

$(NAME) : $(OBJ)
	@cd libft && make all
	@$(AR) $(NAME) $(OBJ)

$(NAME1) : 
	@$(CC) $(NAME) $(LIBFT) main.c -o $(NAME1)
	
%.o: %.c push_swap.h
	@$(CC) -c $<

$(NB) : $(B_OBJ)
	@cd libft && make all
	@$(AR) $(NB) $(B_OBJ)

bonus : $(NB) $(checker)
	
$(checker) : 
	@$(CC) $(NB) $(LIBFT) -o $(checker)

clean :
	@cd libft && make clean
	@$(RM) $(OBJ) $(B_OBJ)

fclean : clean
	@cd libft && make fclean
	@$(RM) $(NAME) $(NAME1) $(checker) $(NB)
	
re : fclean all