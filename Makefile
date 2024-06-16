CC = g++
CFLAGS = -g
WARNINGS = -Wall -Wextra
LINKS = -lraylib

main: main.cpp Player.cpp InputManager.cpp GameManager.cpp App.cpp Barrier.cpp Stage.cpp
	$(CC) $(CFLAGS) $(WARNINGS) main.cpp Player.cpp InputManager.cpp GameManager.cpp App.cpp Barrier.cpp Stage.cpp -o main $(LINKS)
