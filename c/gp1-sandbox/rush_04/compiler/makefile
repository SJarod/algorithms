FLAGS = -W -Wall -Werror
SDL_FLAG = -lSDL2
OBJS = main.o game.o player.o

main.o: ../src/main.c
	gcc -c ../src/main.c

game.o: ../src/game.c
	gcc -c ../src/game.c

player.o: ../src/player.c
	gcc -c ../src/player.c

../bin/snake: $(OBJS)
	gcc $(OBJS) $(FLAGS) $(SDL_FLAG) -g -o ../bin/snake
