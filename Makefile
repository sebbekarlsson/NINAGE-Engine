OS := $(shell uname)

$(info $(OS))

ifeq ($(OS), Darwin)
    FLAGZ=`pkg-config --libs sdl2` -std=c++11 -framework OpenGL -framework GLUT -lSDL2_image -lSDL2_ttf -g
else
    FLAGZ=`pkg-config --libs sdl2` -std=c++11 -lGL -lglut -lSDL2_image -lSDL2_ttf -lGLU -g
endif

G_FLAGZ=-std=c++11

$(info $(FLAGZ))

output:\
    main.o\
    SDLOpenGL.o\
    Instance.o\
    TestObj.o\
    Sprite.o\
    Scene.o\
    TestScene.o
	g++ $(FLAGZ)\
	    main.o\
	    SDLOpenGL.o\
	    Instance.o\
	    TestObj.o\
	    Sprite.o\
	    Scene.o\
	    TestScene.o\
	    -o game.out

main.o: src/main.cpp
	g++ $(G_FLAGZ) -c src/main.cpp

SDLOpenGL.o: src/engine/SDLOpenGL.cpp src/engine/SDLOpenGL.h
	g++ $(G_FLAGZ) -c src/engine/SDLOpenGL.cpp

Sprite.o: src/engine/Sprite.cpp src/engine/Sprite.h
	g++ $(G_FLAGZ) -c src/engine/Sprite.cpp

Instance.o: src/engine/Instance.cpp src/engine/Instance.h
	g++ $(G_FLAGZ) -c src/engine/Instance.cpp

TestObj.o: src/engine/TestObj.cpp src/engine/TestObj.h
	g++ $(G_FLAGZ) -c src/engine/TestObj.cpp

Scene.o: src/engine/Scene.cpp src/engine/Scene.h
	g++ $(G_FLAGZ) -c src/engine/Scene.cpp

TestScene.o: src/engine/TestScene.cpp src/engine/TestScene.h
	g++ $(G_FLAGZ) -c src/engine/TestScene.cpp

clean:
	rm *.o
	rm *.out
