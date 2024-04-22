NAME		=	push_swap
BONUS_NAME	=	checker
CC			= 	cc
CFLAGS		=	-Wall -Wextra -Werror -g #-fsanitize=address
HEADER		=	push_swap.h
BONUS_HEADR	=	./bonus/push_swap_bonus.h
LIBFTDIR	= 	./libft
BONUSDIR	=	./bonus

SRCS 		= 	main.c build_nodes.c kill_program.c psr.c sorting.c \
				move_to_a.c check_a.c move_to_b.c check_b.c utils.c

BONUS_SRCS	=	./bonus/checker.c \
				./bonus/build_nodes_bonus.c \
				./bonus/kill_program_bonus.c \
				./bonus/psr_bonus.c

LIBFT		= 	./libft.a
OBJS		=	$(SRCS:.c=.o)
BONUS_OBJS	=	$(BONUS_SRCS:.c=.o)

$(NAME): $(OBJS)
	@make -C $(LIBFTDIR) all
	@cp $(LIBFTDIR)/libft.a .
	@rm $(LIBFTDIR)/libft.a
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

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