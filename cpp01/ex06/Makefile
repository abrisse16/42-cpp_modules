# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/27 13:24:39 by abrisse           #+#    #+#              #
#    Updated: 2023/02/08 15:10:36 by abrisse          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS
_GREY		=	$'\033[1;30m
_RED		=	$'\033[1;31m
_GREEN		=	$'\033[1;32m
_NO_COLOR	=	$'\033[m

# VARIABLE
NAME	= HarlFilter

CC		= c++

CFLAGS	= -Wall		\
		  -Wextra	\
		  -Werror	\
		  -MMD		\
		  -g		\
		  -std=c++98
IFLAGS	= -I.

OBJS_PATH	= objs/
DEP_PATH	= deps/

SRCS		= main.cpp		\
			  Harl.cpp
OBJS		= $(addprefix $(OBJS_PATH), $(SRCS:.cpp=.o))
DEP			= $(addprefix $(DEP_PATH), $(SRCS:.cpp=.d))

# COMPILATION
$(NAME)	: $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $(OBJS)
	@echo "$(_GREEN)[$(NAME): Executable created]$(_NO_COLOR)"

$(OBJS_PATH)%.o : %.cpp
	@mkdir -p $(OBJS_PATH) $(DEP_PATH)
	@echo "$(_GREY)Compiling : $<$(_NO_COLOR)"
	@$(CC) -o $@ -c $< $(CFLAGS) $(IFLAGS)
	@mv $(@:.o=.d) $(DEP_PATH)

-include $(DEP)

# RULES
all		: $(NAME)

clean	:
	@rm -rf $(OBJS_PATH) $(DEP_PATH)
	@echo "$(_RED)[$(NAME): All objects removed]$(_NO_COLOR)"

fclean	: clean
	@rm -rf $(NAME)
	@echo "$(_RED)[$(NAME): Executable removed]$(_NO_COLOR)"

re		: fclean all

.PHONY	: all clean fclean re