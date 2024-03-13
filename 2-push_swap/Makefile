NAME =		push_swap
CC = 		cc
CFLAGS =	-Wall -Wextra -Werror -fsanitize=address
HEADER =	push_swap.h
LIBFTDIR = 	./libft

SRCS = 		main.c build_nodes.c kill_program.c psr.c sorting.c check_list.c \
			move_to_a.c move_to_b.c find_position.c
LIBFT = 	./libft.a
OBJS =		$(SRCS:.c=.o)

all:			$(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFTDIR) all
	@cp $(LIBFTDIR)/libft.a .
	@rm $(LIBFTDIR)/libft.a
	@$(CC) $(CFLAGS) -g $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(LIBFTDIR)/*.o

fclean: clean
	rm -f $(NAME)
	rm -f libft.a

re: 			fclean all

.PHONY: all clean fclean re