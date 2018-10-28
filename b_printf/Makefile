NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
SRCS = ./b_printf_functions.c ./b_printf.c ./b_printf_itoa.c ./b_printf_flags.c
OBJS = ./b_printf_functions.o ./b_printf.o ./b_printf_itoa.o ./b_printf_flags.o
INC = -I .

$(NAME): printf.h
	$(CC) $(FLAGS) -c $(SRCS) $(INC)
	ar -cr $(NAME) $(OBJS)
	ranlib $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re
