CC = g++
CFLAGS = -Wall -lm -lsfml-graphics -lsfml-window -lsfml-system
HEADERS = src/text.h src/snake.h src/obstacles.h src/obstacle.h src/food.h src/el.h 
OBJECTS = src/text.o src/snake.o src/obstacles.o src/obstacle.o src/food.o src/el.o src/main.o
EXEC = snake_game

.PHONY = default build clean

default: build

build: snake_game

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(EXEC): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

run: build
	./$(EXEC) ${ARGS}

clean:
	-rm -f $(OBJECTS)
	-rm -f $(EXEC)
