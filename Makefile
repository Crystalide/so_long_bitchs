# Source files
SRCS	=	so_long.c
SRCS_BON =

ifeq ($(BONUS), 1)
	SRCS += $(SRCS_BON)
endif

# Object directory and object files
OBJ_DIR = obj/
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
OBJS_BON = $(addprefix $(OBJ_DIR), $(SRCS_BON:.c=.o))

# Libraries and program name
NAME = so_long
LIBFT = libft/libft.a
LIBMLX42 = MLX42/build/libmlx42.a

# MLX42 repository details
MLX42_DIR = MLX42
MLX42_REPO = https://github.com/codam-coding-college/MLX42.git

CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD -MP
MLXFLAGS = -Iinclude -Ilibft -IMLX42/include \
			-Llibft -lft -LMLX42/build -lmlx42 \
			-lglfw -ldl -lm -lpthread
# SAN = -fsanitize=address,bounds,undefined -g3

# Building the final executable
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(LIBMLX42)
	$(CC) $(OBJS) $(LIBFT) $(LIBMLX42) $(MLXFLAGS) -o $(NAME)

$(OBJ_DIR)%.o : %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(LIBFT):
	$(MAKE) -C libft

# Clone MLX42 if missing
$(MLX42_DIR):
	git clone $(MLX42_REPO) $(MLX42_DIR)
	cd $(MLX42_DIR) && git submodule update --init --recursive

# Compile MLX42
$(LIBMLX42): $(MLX42_DIR)/build/Makefile
	@cmake --build MLX42/build

# Runs if valid Makefile is present
$(MLX42_DIR)/build/Makefile: $(MLX42_DIR)
	@cmake -B MLX42/build -S MLX42

bonus:
	@$(MAKE) BONUS=1 --no-print-directory

# Clean object files
clean:
			rm -rf $(OBJ_DIR)
			$(MAKE) clean -C libft

# Full clean (removes executable and libs)
fclean:		clean
			rm -f a.out $(NAME)
			$(MAKE) fclean -C libft
			rm -rf MLX42/build

re:			fclean all

# Include dependency files for tracking
-include $(OBJS:.o=.d)

.PHONY:		all clean fclean re bonus
