FLAGS = -W -Wall -Werror -g
SDL_FLAG = -lSDL2 -lSDL2_image -lSDL2_ttf
OBJS = main.o game.o player.o int_to_alpha.o

main.o: ../src/main.c
	gcc -c -g ../src/main.c

game.o: ../src/game.c
	gcc -c -g ../src/game.c

player.o: ../src/player.c
	gcc -c -g ../src/player.c

int_to_alpha.o: ../src/int_to_alpha.c
	gcc -c -g ../src/int_to_alpha.c

../bin/snake: $(OBJS)
	gcc $(OBJS) $(FLAGS) $(SDL_FLAG) -o ../bin/snake
