NAME			= violence

# Compiler and Flags
CXX				= c++
CXXFLAGS		= -Wall -Wextra -Werror #-std=c++98

# Directories
OBJ_DIR			= objects/

# Files
SRCS			= main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
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