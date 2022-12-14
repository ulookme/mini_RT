# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 04:22:09 by charleshajj       #+#    #+#              #
#    Updated: 2022/12/18 19:50:16 by charleshajj      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT
SRC =	main.c parsing.c parsing2.c parsing3.c parsing4.c \
		check.c delete.c parse_error.c check_object.c check_object2.c \
		write_color.c utils_vec.c vector_process.c vector_process2.c \
		vector_process3.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra -g3
DANGER = -fsanitize=address

all: $(NAME)

dependency:
	make -sC Libft

.c.o:
	gcc $(FLAGS) -c $< -o ${<:.c=.o}

$(NAME): dependency $(OBJ)
	gcc $(DANGER) -o $(NAME) $(OBJ) -LLibft -lft MLX42/libmlx42.a -lglfw 

clean: 
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

aclean: fclean
	@make fclean -sC Libft

re: fclean all

test: all
	@./$(NAME)
	@make fclean

# PROTECTION #

.PHONY: all dependency clean fclean aclean re
