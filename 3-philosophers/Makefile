NAME		=	philosophers
CC			= 	cc
CFLAGS		=	-Wall -Wextra -Werror -g #-fsanitize=address
HEADER		=	philosophers.h

SRCS 		= 	main.c \
				process_input.c \
				tabling_philos.c \
				kill_program.c \
				philo_utils.c

OBJS		=	$(SRCS:.c=.o)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all:	$(NAME)

bonus:	$(BONUS_NAME)

clean:
	@rm -f $(OBJS) $(BONUSDIR)/*.o

fclean: clean
	@rm -f $(NAME)
	@rm -f $(BONUS_NAME)

re: 	fclean all

.PHONY: all bonus clean fclean re