OS := $(shell uname)

$(info $(OS))

G_FLAGZ=-std=c++11 -Wall -g

ifeq ($(OS), Darwin)
    FLAGZ=$(G_FLAGZ) -lninage -framework OpenGL -framework GLUT -lSDL2_image -lSDL2_ttf -lSDL2
else
    FLAGZ=$(G_FLAGZ) -std=c++11 -lninage -lGL -lglut -lSDL2_image -lSDL2_ttf -lGLU -lSDL2
endif

OFILES=\
       main.o\
       MainScene.o\
       Player.o\
       Car.o\
       Ball.o


output: $(OFILES)
	g++ $(OFILES) $(FLAGZ) -o game.out

main.o: src/main.cpp
	g++ $(G_FLAGZ) -c src/main.cpp

MainScene.o: src/MainScene.cpp src/MainScene.h
	g++ $(G_FLAGZ) -c src/MainScene.cpp

Player.o: src/Player.cpp src/Player.h
	g++ $(G_FLAGZ) -c src/Player.cpp

Car.o: src/Car.cpp src/Car.h
	g++ $(G_FLAGZ) -c src/Car.cpp

Ball.o: src/Ball.cpp src/Ball.h
	g++ $(G_FLAGZ) -c src/Ball.cpp

clean:
	-rm *.out
	-rm *.o
