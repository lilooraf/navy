##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/pid_connect.c	\
		src/game_loop.c \
		src/ftc_game_loop.c \
		src/disp_board.c	\
		src/create_map.c	\
		src/create_empty_map.c	\
		src/create_map_tools.c	\
		src/win_lose.c	\
		src/check_map.c	\
		src/check_map_2.c

OBJ	=	$(SRC:.c=.o)

NAME	=	navy

CFLAGS	=	-L lib/my/ -lmy -g -Iinclude

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C ./lib/my/
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	make clean -C ./lib/my/
	rm -f $(OBJ)

fclean:	clean
	make fclean -C ./lib/my/
	rm -f $(NAME)

re:	fclean all
