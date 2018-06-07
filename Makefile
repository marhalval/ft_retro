# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/08 19:18:25 by dkhlopov          #+#    #+#              #
#    Updated: 2018/04/08 19:18:27 by dkhlopov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ./ft_retro

FLAGS = -Wall -Wextra -Werror

SRC = main.cpp Game.cpp ACharacter.cpp Player.cpp Enemy.cpp Bullet.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

%.o : %.cpp
	clang++ $(FLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	clang++ $(FLAGS) $(SRC) -o $(NAME) -lncurses

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
