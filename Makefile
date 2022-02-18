# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: letumany <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/02 19:11:25 by letumany          #+#    #+#              #
#    Updated: 2022/02/18 21:57:54 by letumany         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc

CC_FLAGS	=	-Wall -Wextra -Werror

RM			=	rm -rf

DIR_HEADERS =	./includes/

DIR_SRCS	=	./srcs/

DIR_OBJS	=	./compiled_srcs/

SRC			=	philo.c init.c time.c\
				routine.c utils.c	

SRCS		=	$(SRC)

OBJS 		=	$(SRCS:%.c=$(DIR_OBJS)%.o)

NAME 		=	philo

all:			$(NAME)

$(NAME):		$(OBJS)
				@tput setaf 2 && printf "\033[2K\r.o compiled.\n"
				@$(CC) $(CC_FLAGS) -I $(DIR_HEADERS) $(OBJS) -o $(NAME)
				@tput setaf 2 && printf "$(NAME) created.\n"

$(OBJS):		$(DIR_OBJS)


$(DIR_OBJS)%.o: $(DIR_SRCS)%.c
				@tput setaf 190 && printf "\033[2K\r Compiling $< ⌛ "
				@$(CC) $(CC_FLAGS) -I $(DIR_HEADERS) -c $< -o $@

$(DIR_OBJS):
				@mkdir $(DIR_OBJS)
				
.PHONY:			all clean fclean re norm

clean:
				@$(RM) $(DIR_OBJS)
				@tput setaf 928 && printf ".o deleted.\n"

fclean:			clean
				@$(RM) $(NAME)
				@tput setaf 928 && printf ""$(NAME)" deleted.\n"

re:				fclean all
