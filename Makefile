# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgonzal2 <pgonzal2@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/26 16:40:41 by pgonzal2          #+#    #+#              #
#    Updated: 2024/05/15 21:05:01 by pgonzal2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCS = -IMLX42/include
LIBDIR = -LMLX42 -L/Users/pgonzal2/.brew/Cellar/glfw/3.4/lib
LIB = -lmlx42 -ldl -lglfw

LIBFT_DIR         = libft/
LIBFT             = libft.a
MLX42_DIR         = ./MLX42
NAME              = so_long
CC                = gcc
CFLAGS            = -Wall -Werror -Wextra -Iincludes -g -I$(MLX42_DIR)/include
MLX_FLAGS         = -ldl -pthread -lm -framework Cocoa -framework OpenGL -framework IOKit
RM                = rm -rf

SRC_DIR           = src/
OBJ_DIR           = obj/

FILES_SRC         = main.c map.c flood_fill.c moves.c my_mlx.c\

SRC               = $(addprefix $(SRC_DIR),$(FILES_SRC))
OBJ_SRC           = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

vpath %.c $(SRC_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	
all: $(NAME)

$(NAME): $(OBJ_SRC)
	@$(MAKE) -s all bonus printf gnl -C $(LIBFT_DIR)
	$(CC) $(OBJ_SRC) ${INCS} ${LIBDIR} ${LIB} $(MLX_FLAGS) -L$(LIBFT_DIR) -lft -o $@
	@$(MAKE) -C $(MLX42_DIR)

clean:
	@$(RM) $(OBJ_DIR)
	
fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(MLX42_DIR) clean

re: fclean all

.PHONY: all clean fclean re