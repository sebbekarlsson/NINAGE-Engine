OS := $(shell uname)

$(info $(OS))

ifeq ($(OS), Darwin)
    FLAGZ=`pkg-config --libs sdl2` -std=c++11 -framework OpenGL -framework GLUT -lSDL2_image -lSDL2_ttf -g
else
    FLAGZ=`pkg-config --libs sdl2` -std=c++11 -lGL -lglut -lSDL2_image -lSDL2_ttf -g
endif

G_FLAGZ=-std=c++11

$(info $(FLAGZ))

OFILES=\
       Ninage.o\
       CollisionBox.o\
       Instance.o\
       Entity.o\
       SpriteImage.o\
       Sprite.o\
       Camera.o\
       Scene.o\
       Point.o\
       EngineMath.o\
       Color.o\
       Component.o

LIBFILES=libninage.a libninage.so


all: $(OFILES) $(LIBFILES)	

Ninage.o: src/engine/Ninage.cpp src/engine/Ninage.h
	g++ $(G_FLAGZ) -c src/engine/Ninage.cpp

SpriteImage.o: src/engine/SpriteImage.cpp src/engine/SpriteImage.h
	g++ $(G_FLAGZ) -c src/engine/SpriteImage.cpp

Sprite.o: src/engine/Sprite.cpp src/engine/Sprite.h
	g++ $(G_FLAGZ) -c src/engine/Sprite.cpp

CollisionBox.o: src/engine/CollisionBox.cpp src/engine/CollisionBox.h
	g++ $(G_FLAGZ) -c src/engine/CollisionBox.cpp

Instance.o: src/engine/Instance.cpp src/engine/Instance.h
	g++ $(G_FLAGZ) -c src/engine/Instance.cpp

Entity.o: src/engine/Entity.cpp src/engine/Entity.h
	g++ $(G_FLAGZ) -c src/engine/Entity.cpp

Camera.o: src/engine/Camera.cpp src/engine/Camera.h
	g++ $(G_FLAGZ) -c src/engine/Camera.cpp

Scene.o: src/engine/Scene.cpp src/engine/Scene.h
	g++ $(G_FLAGZ) -c src/engine/Scene.cpp

Point.o: src/engine/utils/Point.cpp src/engine/utils/Point.h
	g++ $(G_FLAGZ) -c src/engine/utils/Point.cpp

EngineMath.o: src/engine/utils/EngineMath.cpp src/engine/utils/EngineMath.h
	g++ $(G_FLAGZ) -c src/engine/utils/EngineMath.cpp

Color.o: src/engine/utils/Color.cpp src/engine/utils/Color.h
	g++ $(G_FLAGZ) -c src/engine/utils/Color.cpp

Component.o: src/engine/Component.cpp src/engine/Component.h
	g++ $(G_FLAGZ) -c src/engine/Component.cpp

libninage.a: $(OFILES)
	ar rcs $@ $^

libninage.so: $(OFILES)
	ar rcs $@ $^

install:
	-rm /usr/local/lib/libninage.*
	-rm -rf /usr/local/include/ninage
	make
	mkdir -p ninage/engine
	mkdir -p ninage/engine/utils
	cp src/engine/*.h ninage/engine/.
	cp src/engine/utils/*.h ninage/engine/utils/.
	mv ninage /usr/local/include/ninage
	mv libninage.a /usr/local/lib/libninage.a
	mv libninage.so /usr/local/lib/libninage.so

clean:
	-rm -rf ninage 
	-rm *.o
	-rm *.out
	-rm *.so
	-rm *.a
