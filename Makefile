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
    fakeGL.o\
    SDLOpenGL.o\
    CollisionBox.o\
    Instance.o\
    TestObj.o\
    TestObj2.o\
    SpriteImage.o\
    Sprite.o\
    Camera.o\
    Scene.o\
    TestScene.o\
    Point.o
	g++ $(FLAGZ)\
	    main.o\
	    fakeGL.o\
	    SDLOpenGL.o\
	    CollisionBox.o\
	    Instance.o\
	    TestObj.o\
	    TestObj2.o\
	    SpriteImage.o\
	    Sprite.o\
	    Camera.o\
	    Scene.o\
	    TestScene.o\
	    Point.o\
	    -o game.out

main.o: src/main.cpp
	g++ $(G_FLAGZ) -c src/main.cpp

fakeGL.o: src/engine/fakeGL.cpp src/engine/fakeGL.h
	g++ $(G_FLAGZ) -c src/engine/fakeGL.cpp

SDLOpenGL.o: src/engine/SDLOpenGL.cpp src/engine/SDLOpenGL.h
	g++ $(G_FLAGZ) -c src/engine/SDLOpenGL.cpp

SpriteImage.o: src/engine/SpriteImage.cpp src/engine/SpriteImage.h
	g++ $(G_FLAGZ) -c src/engine/SpriteImage.cpp

Sprite.o: src/engine/Sprite.cpp src/engine/Sprite.h
	g++ $(G_FLAGZ) -c src/engine/Sprite.cpp

CollisionBox.o: src/engine/CollisionBox.cpp src/engine/CollisionBox.h
	g++ $(G_FLAGZ) -c src/engine/CollisionBox.cpp

Instance.o: src/engine/Instance.cpp src/engine/Instance.h
	g++ $(G_FLAGZ) -c src/engine/Instance.cpp

TestObj.o: src/engine/TestObj.cpp src/engine/TestObj.h
	g++ $(G_FLAGZ) -c src/engine/TestObj.cpp

TestObj2.o: src/engine/TestObj2.cpp src/engine/TestObj2.h
	g++ $(G_FLAGZ) -c src/engine/TestObj2.cpp

Camera.o: src/engine/Camera.cpp src/engine/Camera.h
	g++ $(G_FLAGZ) -c src/engine/Camera.cpp

Scene.o: src/engine/Scene.cpp src/engine/Scene.h
	g++ $(G_FLAGZ) -c src/engine/Scene.cpp

TestScene.o: src/engine/TestScene.cpp src/engine/TestScene.h
	g++ $(G_FLAGZ) -c src/engine/TestScene.cpp

Point.o: src/engine/utils/Point.cpp src/engine/utils/Point.h
	g++ $(G_FLAGZ) -c src/engine/utils/Point.cpp

clean:
	rm *.o
	rm *.out
