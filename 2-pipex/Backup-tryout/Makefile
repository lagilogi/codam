NAME		=	pipex
CC			= 	cc
CFLAGS		=	-Wall -Wextra -Werror -g #-fsanitize=address
HEADER		=	pipex.h
LIBFTDIR	= 	./libft

SRCS 		= 	main.c kill_program.c child_process.c pipex_utils.c

LIBFT		= 	./libft.a
OBJS		=	$(SRCS:.c=.o)

$(NAME): $(OBJS)
	@make -C $(LIBFTDIR) all
	@cp $(LIBFTDIR)/libft.a .
	@rm $(LIBFTDIR)/libft.a
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@rm -f libft.a

all:	$(NAME)

clean:
	@rm -f $(OBJS) $(LIBFTDIR)/*.o

fclean: clean
	@rm -f $(NAME)
	@rm -f $(BONUS_NAME)
	@rm -f libft.a

re: 	fclean all

.PHONY: all clean fclean re