NAME =		libftprintf.a
CC = 		cc
CFLAGS =	-Wall -Wextra -Werror
HEADER =	libftprintf.h
LIBFTDIR = 	../0-libft

sourcefiles = 	ft_printf.c ft_nmbrs.c ft_ptrs.c ft_putchar.c ft_putstr.c

objects =		$(sourcefiles:.c=.o)

all:			$(NAME)

$(NAME): $(objects)
	@make -C $(LIBFTDIR) all
	@cp $(LIBFTDIR)/libft.a .
	@rm $(LIBFTDIR)/libft.a
	@mv libft.a $(NAME)
	ar r $(NAME) $(objects)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(objects) $(LIBFTDIR)/*.o

fclean: clean
	rm -f $(NAME)

re: 			fclean all

.PHONY: all clean fclean re