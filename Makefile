CC		= cc
CFLAGS	= -Wall -Wextra -Werror -std=c99
LFLAGS	= -lX11 -lXext -lz
SRC		= ./cub3d.c ./cub3d-gl.c ./cub3d-math0.c
OBJ		= $(SRC:.c=.o)
LIBFT	= ./libft/libft.a
MLX		= ./minilibx/libmlx.a
PARSER	= ./parser/libpar.a
NAME	= ./cub3d

all: $(NAME)

$(NAME) : $(OBJ) $(MLX) $(PARSER) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@ $(LFLAGS)

$(OBJ) : %.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C ./libft

$(MLX):
	make -C ./minilibx

$(PARSER):
	make -C ./parser

.PHONY: re clean fclean

re: fclean all

clean:
	rm -f $(OBJ)
	make -C ./libft clean
	make -C ./parser clean
	make -C ./minilibx clean

fclean: clean
	rm -f $(NAME)
	make -C ./libft fclean
	make -C ./parser fclean
	make -C ./minilibx fclean

.PHONY: release debug

release: CFLAGS += -DRELEASE -s -O3
release: all

debug: CFLAGS += -DDEBUG -ggdb -g3 -O0
debug: all

.PHONY: gitmodules

gitmodules: .gitmodules
	git submodule update --init
	git submodule foreach git pull origin HEAD
