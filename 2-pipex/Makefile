NAME		=	pipex
CC			= 	cc
CFLAGS		=	-Wall -Wextra -Werror -g #-fsanitize=address
HEADER		=	pipex.h
LIBFTDIR	= 	./libft

SRCS 		= 	main.c kill_program.c command_check.c child_process.c

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

re: 	fclean all

.PHONY: all clean fclean re