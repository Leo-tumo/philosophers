# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: letumany <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/02 19:11:25 by letumany          #+#    #+#              #
#    Updated: 2022/02/16 12:36:29 by letumany         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NORMINETTE	:=	$(shell which norminette)

ifeq (, $(shell which norminette))
	NORMINETTE := ${HOME}/.norminette/norminette.rb
endif

CC			=	gcc

CC_FLAGS	=	-Wall -Wextra -Werror

RM			=	rm -rf

DIR_HEADERS =	./includes/

DIR_SRCS	=	./srcs/

DIR_OBJS	=	./compiled_srcs/

SRC			=	error.c philos.c utils.c	

SRCS		=	$(SRC)

OBJS 		=	$(SRCS:%.c=$(DIR_OBJS)%.o)

NAME 		=	philo

all:			$(NAME)

debug:			CC_FLAGS += -g3 -fsanitize=address
debug:			all

$(NAME):		$(OBJS)
				@tput setaf 2 && printf "\033[2K\r All files compiled into '$(DIR_OBJS)'. ✅\n"
				@$(CC) $(CC_FLAGS) -I $(DIR_HEADERS) $(OBJS) -o $(NAME)
				@tput setaf 2 && printf "\033[2K\r Executable '$(NAME)' created. ✅\n"

$(OBJS):		| $(DIR_OBJS)


$(DIR_OBJS)%.o: $(DIR_SRCS)%.c
				@tput setaf 190 && printf "\033[2K\r Compiling $< ⌛ "
				@$(CC) $(CC_FLAGS) -I $(DIR_HEADERS) -c $< -o $@

$(DIR_OBJS):
				@mkdir $(DIR_OBJS)

clean:
				@$(RM) $(DIR_OBJS)
				@tput setaf 928 && printf "\033[2K\r '"$(DIR_OBJS)"' has been deleted. 🗑️\n"

fclean:			clean
				@$(RM) $(NAME)
				@tput setaf 928 && printf "\033[2K\r '"$(NAME)"' has been deleted. 🗑️\n"

re:				fclean all

norm:
				@$(NORMINETTE) $(DIR_SRCS)
				@$(NORMINETTE) $(DIR_HEADERS)

.PHONY:			all clean fclean re norm
