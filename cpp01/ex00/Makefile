# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/27 14:37:11 by abrisse           #+#    #+#              #
#    Updated: 2023/08/28 11:10:10 by abrisse          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS
_GREY		=	$'\033[1;30m
_RED		=	$'\033[1;31m
_GREEN		=	$'\033[1;32m
_NO_COLOR	=	$'\033[m

# VARIABLE
EXEC	= zombie

CC		= c++

CFLAGS	= -Wall		\
		  -Wextra	\
		  -Werror	\
		  -MMD		\
		  -g		\
		  -std=c++98

ifeq ($(findstring debug,$(MAKECMDGOALS)),debug)
	CFLAGS += -D DEBUG
endif

OBJ_PATH	= objs/
DEP_PATH	= deps/

SRC		= Zombie.cpp	\
		  main.cpp		\
		  newZombie.cpp	\
		  randomChump.cpp
OBJ		= $(addprefix $(OBJ_PATH), $(SRC:.cpp=.o))
DEP		= $(addprefix $(DEP_PATH), $(SRC:.cpp=.d))

# COMPILATION
$(EXEC)	: $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $(OBJ)
	@echo "$(_GREEN)[$(EXEC): Executable created]$(_NO_COLOR)"

$(OBJ_PATH)%.o : %.cpp
	@mkdir -p $(OBJ_PATH) $(DEP_PATH)
	@echo "$(_GREY)Compiling : $<$(_NO_COLOR)"
	@$(CC) -o $@ -c $< $(CFLAGS)
	@mv $(@:.o=.d) $(DEP_PATH)

-include $(DEP)

# RULES
all		: $(NAME)

clean	:
	@rm -rf $(OBJ_PATH) $(DEP_PATH)
	@echo "$(_RED)[$(EXEC): All objects removed]$(_NO_COLOR)"

fclean	: clean
	@rm -rf $(EXEC)
	@echo "$(_RED)[$(EXEC): Executable removed]$(_NO_COLOR)"

re		: fclean all

debug	: re

.PHONY	: all clean fclean re