# **************************************************************************** #
#                                                                              #
#                                                          :::      ::::::::   #
#   Makefile                                             :+:      :+:    :+:   #
#                                                      +:+ +:+         +:+     #
#   By: vruiz-ru <vruiz-ru@student.42madrid.com>     +#+  +:+       +#+        #
#                                                  +#+#+#+#+#+   +#+           #
#   Created: 2025/01/13 14:17:20 by aghergut            #+#    #+#             #
#   Updated: 2026/05/05 21:22:00 by vruiz-ru           ###   ########.fr       #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += -s

# COLORS
GRAY = \033[0;90m
RED = \033[0;91m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
RESET_COLOR = \033[0m

# PROGRAM NAMES
NAME = cub3D
BONUS_NAME = cub3D_bonus

# COMPILER
CC = cc
CFLAGS = -Wall -Wextra -Werror -fPIE
BONUS_CFLAGS = $(CFLAGS) -DCUB3D_BONUS

# LIBRARIES
LIBFT_FLAGS = -Limport/libft -lft
MLX_FLAGS = -Limport/mlx -lmlx -lX11 -lXext -lm
LIBS = $(LIBFT_FLAGS) $(MLX_FLAGS)

# MAKE IMPORTS
MAKE_LIBFT = make -s -C import/libft > /dev/null 2>&1
MAKE_MLX = make -s -C import/mlx > /dev/null 2>&1

# DIRECTORIES
MANDATORY_SRCS_DIR = srcs/mandatory
BONUS_SRCS_DIR = srcs/bonus
OBJS_DIR = objects
BONUS_OBJS_DIR = objects_bonus

# INCLUDE FLAGS
MANDATORY_INCLUDES = -Iimport/mlx -Iimport/libft -Iincludes/mandatory
BONUS_INCLUDES = -Iimport/mlx -Iimport/libft -Iincludes/bonus

# SOURCE LISTS
MANDATORY_SRCS = $(shell find $(MANDATORY_SRCS_DIR) -type f -name '*.c' | sort)
BONUS_SRCS = $(shell find $(BONUS_SRCS_DIR) -type f -name '*_bonus.c' | sort)

# OBJECT LISTS
MANDATORY_OBJS = $(patsubst $(MANDATORY_SRCS_DIR)/%.c,$(OBJS_DIR)/mandatory/%.o,$(MANDATORY_SRCS))
BONUS_OBJS = $(patsubst $(BONUS_SRCS_DIR)/%_bonus.c,$(BONUS_OBJS_DIR)/bonus/%_bonus.o,$(BONUS_SRCS))

all: $(NAME)

bonus:
	@if [ -d $(OBJS_DIR) ] && [ -f $(NAME) ]; then \
		rm -Rf $(OBJS_DIR); \
		rm -f $(NAME); \
		$(MAKE) $(BONUS_NAME); \
	else \
		echo "ERROR: Compile the mandatory part first."; \
	fi
	
$(NAME): $(MANDATORY_OBJS)
	@echo "$(GRAY)Compiling $(NAME) [mandatory]...$(RESET_COLOR)"
	@echo "$(YELLOW)Compiling libft...$(RESET_COLOR)"
	@$(MAKE_LIBFT)
	@echo "$(BLUE)Compiling mlx...$(RESET_COLOR)"
	@$(MAKE_MLX)
	@echo "$(MAGENTA)Linking mandatory version...$(RESET_COLOR)"
	@$(CC) $(CFLAGS) $(MANDATORY_OBJS) $(LIBS) -o $(NAME)
	@echo "$(CYAN)✓ $(NAME) compiled successfully!$(RESET_COLOR)"

$(BONUS_NAME): $(BONUS_OBJS)
	@$(CC) $(BONUS_CFLAGS) $(BONUS_OBJS) $(LIBS) -o $(BONUS_NAME)
	@echo "$(CYAN)✓ $(BONUS_NAME) compiled successfully!$(RESET_COLOR)"

$(OBJS_DIR)/mandatory/%.o: $(MANDATORY_SRCS_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(MANDATORY_INCLUDES) -c $< -o $@

$(BONUS_OBJS_DIR)/bonus/%_bonus.o: $(BONUS_SRCS_DIR)/%_bonus.c
	@mkdir -p $(dir $@)
	@$(CC) $(BONUS_CFLAGS) $(BONUS_INCLUDES) -c $< -o $@

clean:
	@cleaned=false; \
	if [ -d $(OBJS_DIR) ]; then \
		rm -Rf $(OBJS_DIR); \
		cleaned=true; \
	fi; \
	if [ -d $(BONUS_OBJS_DIR) ]; then \
		rm -Rf $(BONUS_OBJS_DIR); \
		cleaned=true; \
	fi; \
	if [ "$$cleaned" = true ]; then \
		echo "Object files cleaned!"; \
	fi
	@make clean -s -C import/libft > /dev/null 2>&1
	@make clean -s -C import/mlx > /dev/null 2>&1

fclean: clean
	@cleaned=false; \
	if [ -f $(NAME) ]; then \
		rm -f $(NAME); \
		cleaned=true; \
	fi; \
	if [ -f $(BONUS_NAME) ]; then \
		rm -f $(BONUS_NAME); \
		cleaned=true; \
	fi; \
	if [ "$$cleaned" = true ]; then \
		echo "All binaries removed!"; \
	fi
	@make fclean -s -C import/libft > /dev/null 2>&1

re: fclean all

.PHONY: all bonus clean fclean re
