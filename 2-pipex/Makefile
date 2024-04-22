NAME		=	pipex
BONUS_NAME	=	pipex_bonus
CC			= 	cc
CFLAGS		=	-Wall -Wextra -Werror -g #-fsanitize=address
HEADER		=	pipex.h
BONUS_HEADR	=	./bonus/pipex_bonus.h
LIBFTDIR	= 	./libft
BONUSDIR	=	./bonus

SRCS 		= 	main.c kill_program.c child_process.c

BONUS_SRCS	=	./bonus/main.c \
				./bonus/kill_program.c \
				./bonus/child_process.c \
				./bonus/pipex_utils.c

LIBFT		= 	./libft.a
OBJS		=	$(SRCS:.c=.o)
BONUS_OBJS	=	$(BONUS_SRCS:.c=.o)

$(NAME): $(OBJS)
	@make -C $(LIBFTDIR) all
	@cp $(LIBFTDIR)/libft.a .
	@rm $(LIBFTDIR)/libft.a
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@rm -f libft.a

$(BONUS_NAME): $(BONUS_OBJS)
	@make -C $(LIBFTDIR) all
	@cp $(LIBFTDIR)/libft.a .
	@rm $(LIBFTDIR)/libft.a
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)
	@rm libft.a

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