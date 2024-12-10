NAME			= phonebook

# Compiler & flags
CXX				= c++
# CXXFLAGS		= -Wall -Wextra -Werror -std=c++98

# Directories
OBJ_DIR			= objects/

# Files
SRCS			= phonebook.cpp phonebook_utils.cpp
OBJS			= $(patsubst %.cpp,$(OBJ_DIR)%.o,$(SRCS))

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CXX) $(OBJS) -o $(NAME)

$(OBJ_DIR)%.o:	%.cpp
				mkdir -p $(@D)
				$(CXX) $(CXXFLAGS) -c $< -o $@

clean:			
				@rm -rf $(OBJ_DIR)
				@echo "Cleaned up object files"

fclean:			clean
				@rm $(NAME)
				@echo "Cleaned up executable"

re:				fclean all

.PHONY: 		all clean fclean re