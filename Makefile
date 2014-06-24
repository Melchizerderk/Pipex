# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bcrespin <bcrespin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/05/07 16:47:32 by bcrespin          #+#    #+#              #
#    Updated: 2014/05/11 19:47:21 by bcrespin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= gcc
CFLAG= -Wall -Werror -Wextra -g
SRC= pipe.c ft_dup.c
OBJ= $(SRC:.c=.o)
LIB= ./libft
TARGET= pipex

all:$(TARGET)

$(TARGET):
	@(cd libft/ && $(MAKE))
	$(CC) -c $(CFLAG) -I headers -I $(LIB) -c $(SRC)
	$(CC) -o $(TARGET) -L $(LIB) -lft $(OBJ)

clean:
	@(cd libft/ && $(MAKE) $@)
	rm -f $(OBJ)

fclean:
	@(cd libft/ && $(MAKE) $@)
	rm -f $(TARGET)

re: fclean all
