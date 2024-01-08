# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/16 18:24:19 by abrisse           #+#    #+#              #
#    Updated: 2024/01/08 02:59:49 by abrisse          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS

_GREY		= $'\033[1;30m
_RED		= $'\033[1;31m
_GREEN		= $'\033[1;32m
_NO_COLOR	= $'\033[m


# VARIABLE

EXEC	= RPN

CC		= c++

CFLAGS	= -Wall		\
		  -Wextra	\
		  -Werror	\
		  -std=c++98

DFLAGS	= -g -D DEBUG -Wno-unused

ifeq ($(findstring debug, $(MAKECMDGOALS)), debug)
	CFLAGS += $(DFLAGS)
endif

OBJ_PATH	= objs/
DEP_PATH	= deps/

SRC			= main.cpp	\
			  RPN.cpp
OBJ			= $(addprefix $(OBJ_PATH), $(SRC:.cpp=.o))
DEP			= $(addprefix $(DEP_PATH), $(SRC:.cpp=.d))


# COMPILATION

$(EXEC) : $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $(OBJ)
	@echo "$(_GREEN)[$(EXEC): Executable created]$(_NO_COLOR)"

$(OBJ_PATH)%.o : %.cpp
	@mkdir -p $(OBJ_PATH) $(DEP_PATH)
	@echo "$(_GREY)Compiling: $<$(_NO_COLOR)"
	@$(CC) $(CFLAGS) -MMD -o $@ -c $<
	@mv $(@:.o=.d) $(DEP_PATH)

-include $(DEP)


# RULES

all		: $(EXEC)

clean	:
	@rm -rf $(OBJ_PATH) $(DEP_PATH)
	@echo "$(_RED)[$(EXEC): Objects removed]$(_NO_COLOR)"

fclean	: clean
	@rm -f $(EXEC)
	@echo "$(_RED)[$(EXEC): Executable removed]$(_NO_COLOR)"

re		: fclean all

debug	: re

.PHONY	: all clean fclean re debug