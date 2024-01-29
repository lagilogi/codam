NAME	:= Game
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX	:= ./MLX42
LIBFTDR	:= ./libft

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
LIBFT	:= ./libft.a
SRCS	:= main.c run_game.c load_map.c kill_game.c build_game.c so_long_utils.c #$(shell find ./src -iname "*.c")
OBJS	:= ${SRCS:.c=.o}

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@make -C $(LIBFTDR) all
	@cp $(LIBFTDR)/libft.a .
	@rm $(LIBFTDR)/libft.a
	@$(CC) -g $(OBJS) $(LIBS) $(LIBFT) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	@rm -f $(objects) $(LIBFTDR)/*.o

fclean: clean
	@rm -rf $(NAME)
	@rm libft.a

re: clean all

.PHONY: all clean fclean re libmlx