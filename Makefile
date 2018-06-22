# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dglaser <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/05 14:24:42 by dglaser           #+#    #+#              #
#    Updated: 2017/10/23 14:43:39 by dmontoya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
PROJECT = fillit
NAME = fillit

SRC =	ft_putchar.c \
	  	ft_putstr.c \
	  	ft_memset.c \
	  	ft_memalloc.c \
	  	ft_error.c \
	  	recursive_backtracking.c \
	  	placement.c \
	  	tetrisfigures.c \
	  	main.c \
		ft_figadjust.c \
		utilities.c \
		ft_twotets.c \
		ft_onetet.c

GREEN = \033[32m
CYAN = \033[36m
NO_COLOR=\033[0m

PREP_STR = $(CYAN)Preparing $(PROJECT)...$(NO_COLOR)
CLEANO_STR = $(CYAN)Cleaning object files...$(NO_COLOR)
CLEANB_STR = $(CYAN)Cleaning binary files...$(NO_COLOR)
OK_STR = $(GREEN)[OK]$(NO_COLOR)

C_FILES = $(addprefix src/, $(SRC))
INCL = -I inc/

FLAGS = -Wall -Wextra -Werror
CC = gcc

all: $(NAME)

$(NAME):
	@echo "$(PREP_STR)"
	@mkdir -p obj
	@$(CC) $(FLAGS) -c $(C_FILES) $(INCL)
	@mv *.o obj/
	@$(CC) $(FLAGS) $(C_FILES) $(INCL) -o $(NAME)
	@echo "$(PROJECT) Complete! $(NAME)...$(OK_STR)"

clean:
	@echo "$(CLEANO_STR)"
	@rm -f obj/*.o
	@echo "$(OK_STR)"

fclean: clean
	@echo "$(CLEANB_STR)"
	@rm -f $(NAME)
	@rm -rf obj
	@echo "$(OK_STR)"

re:	fclean all
