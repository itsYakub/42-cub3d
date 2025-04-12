AR		= ar
ARFLAGS	= rcs
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -std=c99
LIBFT	= ../libft/libft.a
SRC		= ./par-dat0.c ./par-dat1.c ./par-dat2.c ./par-fgetc.c ./par-extract-data0.c ./par-extract-data1.c ./par-extract-data2.c ./par-dat-bounds0.c ./par-utils0.c ./par-map0.c
OBJ		= $(SRC:.c=.o)
NAME	= libpar.a

all: $(NAME)

$(NAME) : $(OBJ)
	$(AR) $(ARFLAGS) $@ $^

$(OBJ) : %.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT) :
	make -C ../libft

.PHONY: re clean fclean

re: fclean all

clean:
	make -C ../libft clean
	rm -f $(OBJ)

fclean: clean
	make -C ../libft fclean
	rm -f $(NAME)

.PHONY: release debug

release: CFLAGS += -DRELEASE -O3 -s
release: all
debug: CFLAGS += -DDEBUG -O0 -ggdb -g3
debug: all

.PHONY: test

test: $(NAME) $(LIBFT)
	$(CC) $(CFLAGS) -ggdb -o $@.out ./test.c $^
