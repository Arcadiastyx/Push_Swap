# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inaranjo <inaranjo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/25 15:53:11 by inaranjo          #+#    #+#              #
#    Updated: 2023/05/02 11:23:58 by inaranjo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

LIBFT = $(LIBFT_PATH)libft.a
LIBFT_PATH = libft/

SRC =	main.c \
		check_args.c \
		utils.c \
		manage_stack.c \
		operations.c \
		sort_logic.c \
		sort_3.c \
		sort_4.c \
		sort_5.c \
		radix_sort.c \
		
						
		
CC = gcc

CFLAGS = -Wall -Wextra -Werror

OBJ = ${SRC:.c=.o}

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

all : subsystems $(NAME)

%.o : %.c
	@echo $(Y)Compiling [$<]...$(X)
	@$(CC) $(CFLAGS) -g -c $< -o ${<:.c=.o} 
	@printf $(UP)$(CUT)

subsystems :
	@echo $(B)
	make -C $(LIBFT_PATH) all

$(NAME): $(OBJ)
	@echo $(Y)Compiling [$(SRC)]...$(X)
	@echo $(G)Finished [$(SRC)]$(X)
	@echo
	@echo $(Y)Compiling [$(NAME)]...$(X)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo $(G)Finished [$(NAME)]$(X)

clean:
	@make clean -C $(LIBFT_PATH)
	@rm -f $(OBJ)
	@echo $(R)Removed [$(OBJ)]$(X)


fclean: clean
	@make fclean -C $(LIBFT_PATH)
	@rm -f $(NAME)
	@rm -f $(LIBFT)
	@echo $(R)Removed [$(NAME)]$(X)

re: fclean all

.PHONY: all clean fclean re