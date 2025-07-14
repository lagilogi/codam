NAME			= RPN

# Compiler and Flags
CXX				= c++
CXXFLAGS		= -Wall -Wextra -Werror -Wshadow

# Directories
OBJ_DIR			= objects/

# Files
SRCS			= main.cpp RPN.cpp
OBJS			= $(patsubst %.cpp,$(OBJ_DIR)%.o,$(SRCS))

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CXX) $(OBJS) -o $(NAME)

$(OBJ_DIR)%.o:	%.cpp
				mkdir -p $(@D)
				$(CXX) $(CXXFLAGS) -c $< -o $@

clean:			
				@-rm -rf $(OBJ_DIR) && echo "Cleaned up object files"

fclean:			clean
				@-rm $(NAME) && echo "Cleaned up executable"

re:				fclean all

.PHONY: 		all clean fclean re