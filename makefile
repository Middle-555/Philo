# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/08 14:12:29 by kpourcel          #+#    #+#              #
#    Updated: 2024/11/22 13:53:59 by kpourcel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the program
NAME = philo

# Compiler and flags
CC = cc
CFLAGS = -Wall -Werror -Wextra -g -pthread

# Directories
SRC_DIR = src/
OBJ_DIR = obj/
INC_DIR = include/

# Source and object files
SRC = main.c data.c  philo_routine.c philo.c utils.c checking_error.c utils2.c tester.c philo_death.c free_data.c philo_eat.c
OBJ = $(SRC:%.c=$(OBJ_DIR)%.o)

# The main rule
all: $(NAME)

# Linking the program
$(NAME): $(OBJ)
	@echo "\033[0;33mLinking the program -> ⏳\033[0m"
	@$(CC) $(OBJ) -o $@ -I $(INC_DIR)
	@echo "\033[0;32mProgram successfully linked -> ✅\033[0m\n"

# Creating the object files
$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@echo "\033[0;33mCompiling $< -> ⏳\033[0m"
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR)
	@echo "\033[0;32m$< successfully compiled -> ✅\033[0m\n"

# Create the obj directory
$(OBJ_DIR):
	@mkdir -p $@

# Cleaning up
clean:
	@echo "\033[0;31mCleaning object files -> 🗑️\033[0m"
	@rm -f $(OBJ_DIR)*
	@echo "\033[0;32mClean up done -> ✅\033[0m\n"

fclean: clean
	@echo "\033[0;31mRemoving the program -> 🗑️\033[0m"
	@rm -f $(NAME)
	@echo "\033[0;32mProgram removed -> ✅\033[0m\n"

# Rebuilding the project
re: fclean all
