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
    CollisionBox.o\
    Instance.o\
    TestObj.o\
    Sprite.o\
    Camera.o\
    Scene.o\
    TestScene.o\
    Point.o
	g++ $(FLAGZ)\
	    main.o\
	    SDLOpenGL.o\
	    CollisionBox.o\
	    Instance.o\
	    TestObj.o\
	    Sprite.o\
	    Camera.o\
	    Scene.o\
	    TestScene.o\
	    Point.o\
	    -o game.out

main.o: src/main.cpp
	g++ $(G_FLAGZ) -c src/main.cpp

SDLOpenGL.o: src/engine/SDLOpenGL.cpp src/engine/SDLOpenGL.h
	g++ $(G_FLAGZ) -c src/engine/SDLOpenGL.cpp

Sprite.o: src/engine/Sprite.cpp src/engine/Sprite.h
	g++ $(G_FLAGZ) -c src/engine/Sprite.cpp

CollisionBox.o: src/engine/CollisionBox.cpp src/engine/CollisionBox.h
	g++ $(G_FLAGZ) -c src/engine/CollisionBox.cpp

Instance.o: src/engine/Instance.cpp src/engine/Instance.h
	g++ $(G_FLAGZ) -c src/engine/Instance.cpp

TestObj.o: src/engine/TestObj.cpp src/engine/TestObj.h
	g++ $(G_FLAGZ) -c src/engine/TestObj.cpp

Camera.o: src/engine/Camera.cpp src/engine/Camera.h
	g++ $(G_FLAGZ) -c src/engine/Camera.cpp

Scene.o: src/engine/Scene.cpp src/engine/Scene.h
	g++ $(G_FLAGZ) -c src/engine/Scene.cpp

TestScene.o: src/engine/TestScene.cpp src/engine/TestScene.h
	g++ $(G_FLAGZ) -c src/engine/TestScene.cpp

Point.o: src/utils/Point.cpp src/utils/Point.h
	g++ $(G_FLAGZ) -c src/utils/Point.cpp

clean:
	rm *.o
	rm *.out
