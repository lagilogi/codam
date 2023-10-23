NAME =			libft.a
sourcefiles = 	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
		ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c \
		ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
		ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
		ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c \
		ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
		ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c \
		ft_toupper.c ft_memcpy.c

bonusfiles = 	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
				ft_lstadd_back.c

objects =		$(sourcefiles:.c=.o)
bobjects =		$(bonusfiles:.c=.o)

all:			$(NAME)

$(NAME):		$(objects)
	ar rcs libft.a $(objects)

%.o: %.c
	cc -Wall -Wextra -Werror -c $< -o $@

bonus:			$(objects) $(bobjects)
	ar rcs libft.a $(objects) $(bobjects)

clean:
	rm -f $(objects) $(bobjects)

fclean: clean
	rm -f $(NAME)

re: 			fclean all

.PHONY: all bonus clean fclean re