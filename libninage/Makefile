OS := $(shell uname)

$(info $(OS))

ifeq ($(OS), Darwin)
    FLAGZ=-Wall -std=c++11 -framework OpenGL -framework GLUT -lSDL2_image -lSDL2_ttf -lSDL2 -g
else
    FLAGZ=-Wall -std=c++11 -lGL -lglut -lSDL2_image -lSDL2_ttf -lSDL2 -g
endif

G_FLAGZ=-std=c++11 -Wall -g

$(info $(FLAGZ))

OFILES=\
       Ninage.o\
       CollisionBox.o\
       Instance.o\
       Entity.o\
       Illustration.o\
       IllustrationStack.o\
       Camera.o\
       Scene.o\
       Point.o\
       EngineMath.o\
       Color.o\
       Model3D.o\
       ModelLoader.o\
       GraphicsCard.o\
       Component.o

LIBFILES=libninage.a libninage.so


all: $(OFILES) $(LIBFILES)	

Ninage.o: src/Ninage.cpp src/includes/Ninage.h
	g++ $(G_FLAGZ) -c src/Ninage.cpp

Illustration.o: src/Illustration.cpp src/includes/Illustration.h
	g++ $(G_FLAGZ) -c src/Illustration.cpp

IllustrationStack.o: src/IllustrationStack.cpp src/includes/IllustrationStack.h
	g++ $(G_FLAGZ) -c src/IllustrationStack.cpp

CollisionBox.o: src/CollisionBox.cpp src/includes/CollisionBox.h
	g++ $(G_FLAGZ) -c src/CollisionBox.cpp

Instance.o: src/Instance.cpp src/includes/Instance.h
	g++ $(G_FLAGZ) -c src/Instance.cpp

Entity.o: src/Entity.cpp src/includes/Entity.h
	g++ $(G_FLAGZ) -c src/Entity.cpp

Camera.o: src/Camera.cpp src/includes/Camera.h
	g++ $(G_FLAGZ) -c src/Camera.cpp

Scene.o: src/Scene.cpp src/includes/Scene.h
	g++ $(G_FLAGZ) -c src/Scene.cpp

Point.o: src/utils/Point.cpp src/includes/utils/Point.h
	g++ $(G_FLAGZ) -c src/utils/Point.cpp

EngineMath.o: src/utils/EngineMath.cpp src/includes/utils/EngineMath.h
	g++ $(G_FLAGZ) -c src/utils/EngineMath.cpp

Color.o: src/utils/Color.cpp src/includes/utils/Color.h
	g++ $(G_FLAGZ) -c src/utils/Color.cpp

Model3D.o: src/utils/Model3D.cpp src/includes/utils/Model3D.h
	g++ $(G_FLAGZ) -c src/utils/Model3D.cpp

ModelLoader.o: src/utils/ModelLoader.cpp src/includes/utils/ModelLoader.h
	g++ $(G_FLAGZ) -c src/utils/ModelLoader.cpp

GraphicsCard.o: src/utils/GraphicsCard.cpp src/includes/utils/GraphicsCard.h
	g++ $(G_FLAGZ) -c src/utils/GraphicsCard.cpp

Component.o: src/Component.cpp src/includes/Component.h
	g++ $(G_FLAGZ) -c src/Component.cpp

libninage.a: $(OFILES)
	ar rcs $@ $^

libninage.so: $(OFILES)
	ar rcs $@ $^

install:
	-rm /usr/local/share/ninage
	-rm /usr/local/lib/libninage.*
	-rm -rf /usr/local/include/ninage
	make
	cp -r ninage /usr/local/share/ninage
	cp -r src/includes /usr/local/include/ninage
	mv libninage.a /usr/local/lib/libninage.a
	mv libninage.so /usr/local/lib/libninage.so

clean:
	-rm *.o
	-rm *.out
	-rm *.so
	-rm *.a
