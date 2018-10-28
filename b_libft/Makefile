CC = gcc
NAME = libft.a
FLAGS = -Wall -Wextra -Werror
SRCS = ./ft_isdigit.c ./ft_memset.c ./ft_strchr.c ./ft_strdup.c ./ft_strcmp.c ./ft_strcpy.c ./ft_strlen.c ./ft_strncpy.c ./ft_tolower.c ./ft_toupper.c
OBJS = ./ft_isdigit.o ./ft_memset.o ./ft_strchr.o ./ft_strdup.o ./ft_strcmp.o ./ft_strcpy.o ./ft_strlen.o ./ft_strncpy.o ./ft_tolower.o ./ft_toupper.o
INC = -I .

all: $(NAME)

$(NAME): libft.h
	$(CC) $(FLAGS) -c $(SRCS) $(INC)
	ar -cr $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re
