# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inaranjo <inaranjo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/07 11:20:26 by inaranjo          #+#    #+#              #
#    Updated: 2023/03/08 15:41:48 by inaranjo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_C = client
NAME_S = server

LIBFT = $(LIBFT_PATH)libft.a
LIBFT_PATH = libft/

SRC_C = client.c
SRC_S = server.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror

#${SRC_C:.c=.o} est utilisé pour définir la liste des fichiers objet
OBJ_C = ${SRC_C:.c=.o}
OBJ_S = ${SRC_S:.c=.o}

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

all : subsystems $(NAME_C) $(NAME_S)

%.o : %.c
	@echo $(Y)Compiling [$<]...$(X)
	@$(CC) $(CFLAGS) -g -c $< -o ${<:.c=.o}
	@printf $(UP)$(CUT)

subsystems :
	@echo $(B)
	make -C $(LIBFT_PATH) all

$(NAME_C): $(OBJ_C)
	@echo $(Y)Compiling [$(SRC_C)]...$(X)
	@echo $(G)Finished [$(SRC_C)]$(X)
	@echo
	@echo $(Y)Compiling [$(NAME_C)]...$(X)
	@$(CC) $(CFLAGS) $(OBJ_C) $(LIBFT) -o $(NAME_C) 
	@echo $(G)Finished [$(NAME_C)]$(X)

$(NAME_S): $(OBJ_S)
	@echo $(Y)Compiling [$(SRC_S)]...$(X)
	@echo $(G)Finished [$(SRC_S)]$(X)
	@echo
	@echo $(Y)Compiling [$(NAME_S)]...$(X)
	@$(CC) $(CFLAGS) $(OBJ_S) $(LIBFT) -o $(NAME_S) 
	@echo $(G)Finished [$(NAME_S)]$(X)

clean:
	@make clean -C $(LIBFT_PATH)
	@rm -f $(OBJ_C)
	@rm -f $(OBJ_S)
	@echo $(R)Removed [$(OBJ_C)]$(X)
	@echo $(R)Removed [$(OBJ_S)]$(X)

fclean: clean
	@make fclean -C $(LIBFT_PATH)
	@rm -f $(NAME_C)
	@rm -f $(NAME_S)
	@rm -f $(LIBFT)
	@echo $(R)Removed [$(NAME_C)]$(X)
	@echo $(R)Removed [$(NAME_S)]$(X)

re: fclean all

.PHONY: all clean fclean re