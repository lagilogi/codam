NAME		=	philosophers
CC			= 	cc
CFLAGS		=	-Wall -Wextra -Werror -g -fsanitize=address
HEADER		=	philosophers.h
LIBFTDIR	= 	./libft

SRCS 		= 	main.c

LIBFT		= 	./libft.a
OBJS		=	$(SRCS:.c=.o)

$(NAME): $(OBJS)
	@make -C $(LIBFTDIR) all
	@cp $(LIBFTDIR)/libft.a .
	@rm $(LIBFTDIR)/libft.a
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@rm -f libft.a

all:	$(NAME)

bonus:	$(BONUS_NAME)

clean:
	@rm -f $(OBJS) $(LIBFTDIR)/*.o $(BONUSDIR)/*.o

fclean: clean
	@rm -f $(NAME)
	@rm -f $(BONUS_NAME)
	@rm -f libft.a

re: 	fclean all

.PHONY: all bonus clean fclean re