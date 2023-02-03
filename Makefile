# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eelhafia <eelhafia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/13 18:34:16 by eelhafia          #+#    #+#              #
#    Updated: 2023/02/03 15:22:36 by eelhafia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
RM = rm -f
AR = ar rc
CC = cc -Wall -Wextra -Werror 
NAME1 = push_swap

SRC = push_swap.c linked_list_op.c oper_stk.c function_help.c function_help_1.c function_check.c swap_all.c functions.c

LIBFT = libft.a

OBJ = $(SRC:.c=.o)

all : $(NAME) $(NAME1)

	
$(NAME) : $(OBJ)
	cd libft && make all
	$(AR) $(NAME) $(OBJ)

$(NAME1) :
	$(CC) $(NAME) $(LIBFT)  -o push_swap  
	
%.o: %.c push_swap.h
	$(CC) -c $<
	
clean :
	cd libft && make clean
	$(RM) $(OBJ)

fclean : clean
	cd libft && make fclean
	$(RM) $(NAME) $(NAME1)
	
re : fclean all