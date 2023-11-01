NAME =	libftprintf.a
CC = 	cc
HEADER =	libftprintf.h
sourcefiles = 	ft_printf.c ft_nmbrs.c ft_ptrs.c ft_putchar.c ft_putstr.c

objects =		$(sourcefiles:.c=.o)

all:			$(NAME)

$(NAME):		$(objects)
	ar rcs libftprintf.a $(objects)

%.o: %.c
	cc -Wall -Wextra -Werror -c $< -o $@

clean:
	rm -f $(objects)

fclean: clean
	rm -f $(NAME)

re: 			fclean all

.PHONY: all clean fclean re