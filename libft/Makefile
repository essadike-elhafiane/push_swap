
NAME = ../libft.a
CC = cc
FLG = -Wall -Wextra -Werror
RM = rm -f
AR = ar rc

FILES = ft_striteri.c ft_memcmp.c  ft_bzero.c ft_putnbr_fd.c ft_strmapi.c ft_itoa.c \
	ft_putendl_fd.c ft_putchar_fd.c ft_putstr_fd.c ft_strtrim.c ft_strjoin.c ft_strdup.c \
	ft_calloc.c  ft_isalnum.c ft_isalpha.c \
	ft_isascii.c ft_isdigit.c ft_isprint.c \
	ft_memchr.c ft_memset.c ft_memcpy.c \
	ft_strlen.c ft_strncmp.c ft_strlcat.c ft_strlcpy.c ft_atoi.c \
	ft_strchr.c ft_strrchr.c ft_strnstr.c \
	ft_tolower.c ft_toupper.c ft_memmove.c ft_split.c \
	ft_substr.c

B_FILES = ft_lstiter.c ft_lstclear.c ft_lstdelone.c ft_lstlast.c ft_lstsize.c \
	ft_lstadd_back.c ft_lstadd_front.c ft_lstnew.c 

OBJ = $(FILES:.c=.o)

B_OBJ = $(B_FILES:.c=.o)

all : $(NAME) bonus

$(NAME) : $(OBJ)
	$(AR) $(NAME) $(OBJ)
		
bonus : $(B_OBJ)
	$(AR) $(NAME) $(B_OBJ)

%.o: %.c libft.h
	$(CC) $(FLG) -c $<

clean:
	$(RM) $(OBJ) $(B_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
