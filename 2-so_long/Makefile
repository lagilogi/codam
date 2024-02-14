NAME	:= so_long
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast -fsanitize=address
LIBMLX	:= ./MLX42
LIBFTDR	:= ./libft

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
LIBFT	:= ./libft.a
SRCS	:= main.c run_game.c load_map.c kill_game.c build_game.c \
			map_checker.c win_lose.c player_movement.c so_long_utils.c \
			moves_on_screen_bonus.c enemy_bonus.c enemy_movement_bonus.c animation_bonus.c
OBJS	:= ${SRCS:.c=.o}

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@make -C $(LIBFTDR) all
	@cp $(LIBFTDR)/libft.a .
	@rm $(LIBFTDR)/libft.a
	@$(CC) $(CFLAGS) -g $(OBJS) $(LIBS) $(LIBFT) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	@rm -f $(objects) $(LIBFTDR)/*.o

fclean: clean
	@rm -rf $(NAME)
	@rm libft.a

re: clean all

.PHONY: all clean fclean re libmlx