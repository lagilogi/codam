NAME		=	philosophers
CC			= 	cc
CFLAGS		=	-g -Wall -Wextra -Werror #-fsanitize=address
HEADER		=	philosophers.h
OBJ_DIR		=	objects/

SRCS 		= 	main.c \
				process_input.c \
				tabling_philos.c \
				kill_program.c \
				philo_utils.c

# OBJS		=	$(SRCS:.c=.o)
OBJS		=	$(patsubst %.c,$(OBJ_DIR)%.o,$(SRCS))


all:	$(NAME)

$(NAME):	$(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)%.o:	%.c
				@mkdir -p $(@D)
				$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: 	fclean all

.PHONY: all bonus clean fclean re