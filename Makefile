# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rharing <rharing@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/06 12:59:48 by rharing           #+#    #+#              #
#    Updated: 2022/04/06 12:59:49 by rharing          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
LIBFT_DIR = ./Libs/libft
LIBFT = $(LIBFT_DIR)/libft.a
FLAGS = -Wall -Werror -Wextra
INC = -I ./includes
SRC = ./src/pipex.c ./src/utils.c
OBJ = $(SRC:%.c=%.o)

all: $(NAME)
$(NAME): $(LIBFT) $(OBJ)
	gcc  $(OBJ) $(LIBFT) $(FLAGS) -o $(NAME) 

%.o: %.c
	gcc $(INC) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
.PHONY: all clean fclean re