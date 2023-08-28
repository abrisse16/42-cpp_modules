# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/28 08:47:56 by abrisse           #+#    #+#              #
#    Updated: 2023/08/28 08:47:57 by abrisse          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS
_GREY		=	$'\033[1;30m
_RED		=	$'\033[1;31m
_GREEN		=	$'\033[1;32m
_NO_COLOR	=	$'\033[m

# VARIABLE
EXEC	= megaphone

CC		= c++

CFLAGS	= -Wall		\
		  -Wextra	\
		  -Werror	\
		  -MMD		\
		  -g		\
		  -std=c++98

OBJS_PATH	= objs/
DEP_PATH	= deps/

SRCS		= megaphone.cpp
OBJS		= $(addprefix $(OBJS_PATH), $(SRCS:.cpp=.o))
DEP			= $(addprefix $(DEP_PATH), $(SRCS:.cpp=.d))

# COMPILATION
$(EXEC)	: $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $(OBJS)
	@echo "$(_GREEN)[$(EXEC): Executable created]$(_NO_COLOR)"

$(OBJS_PATH)%.o : %.cpp
	@mkdir -p $(OBJS_PATH) $(DEP_PATH)
	@echo "$(_GREY)Compiling : $<$(_NO_COLOR)"
	@$(CC) -o $@ -c $< $(CFLAGS) $(IFLAGS)
	@mv $(@:.o=.d) $(DEP_PATH)

-include $(DEP)

# RULES
all		: $(EXEC)

clean	:
	@rm -rf $(OBJS_PATH) $(DEP_PATH)
	@echo "$(_RED)[$(EXEC): All objects removed]$(_NO_COLOR)"

fclean	: clean
	@rm -rf $(EXEC)
	@echo "$(_RED)[$(EXEC): Executable removed]$(_NO_COLOR)"

re		: fclean all

.PHONY	: all clean fclean re
