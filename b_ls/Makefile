NAME = libftls.a
CC = gcc
FLAGS = -Wall -Wextra -Werror -g
SRCS = ./b_functions.c ./b_structs.c ./b_sort.c ./b_print.c ./b_flags.c ./b_format.c
OBJS = ./b_functions.o ./b_structs.o ./b_sort.o ./b_print.o	./b_flags.o ./b_format.o
INC = -I .

$(NAME): ls.h
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
