CC		= cc
CFLAGS	= -Wall -Wextra -Werror -std=c99
LFLAGS	= -lX11 -lXext -lz -lm
SRC		= 	./cub3d.c			\
			./cub3d-gl.c		\
			./cub3d-math0.c		\
			./cub3d-math1.c		\
			./cub3d-player0.c	\
			./cub3d-player1.c	\
			./cub3d-input.c		\
			./cub3d-dda0.c		\
			./cub3d-dda1.c		\
			./cub3d-time.c		\
			./cub3d-assets.c	\
			./cub3d-texture0.c	\
			./cub3d-minimap.c
OBJ		= $(SRC:.c=.o)
LIBFT	= ./libft/libft.a
MLX		= ./minilibx/libmlx.a
PARSER	= ./parser/libpar.a
NAME	= ./cub3d

MINILIBX_REPO = https://github.com/42Paris/minilibx-linux.git
MINILIBX_DIR  = ./minilibx

all: $(MINILIBX_DIR) $(NAME)

$(MINILIBX_DIR):
	@if [ ! -d "$(MINILIBX_DIR)" ]; then \
		echo "Cloning minilibx..."; \
		git clone $(MINILIBX_REPO) $(MINILIBX_DIR); \
	fi

$(NAME) : $(OBJ) $(MLX) $(PARSER) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@ $(LFLAGS)

$(OBJ) : %.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C ./libft

$(MLX): $(MINILIBX_DIR)
	make -C $(MINILIBX_DIR)

$(PARSER):
	make -C ./parser

.PHONY: re clean fclean

re: fclean all

clean:
	rm -f $(OBJ)
	make -C ./libft clean
	make -C ./parser clean
	make -C $(MINILIBX_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C ./libft fclean
	make -C ./parser fclean
	rm -rf $(MINILIBX_DIR)

.PHONY: release debug

release: CFLAGS += -DRELEASE -O3
release: all

debug: CFLAGS += -DDEBUG -ggdb -g3 -O0
debug: all
