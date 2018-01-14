OS := $(shell uname)

$(info $(OS))

G_FLAGZ=-std=c++11 -Wall -g

ifeq ($(OS), Darwin)
    FLAGZ=$(G_FLAGZ) -lninage -framework OpenGL -framework GLUT -lSDL2_image -lSDL2_ttf -lSDL2
else
    FLAGZ=$(G_FLAGZ) -lninage -lGL -lglut -lSDL2_image -lSDL2_ttf -lGLU -lSDL2
endif


SOURCES = $(wildcard src/*.cpp) 
OBJECTS = $(SOURCES:.cpp=.o)
LIBFILES=libninage.a libninage.so
SUBDIRS = src/lib/ResourceManager
.PHONY: all $(SUBDIRS)



%.o: %.cpp includes/%.h
	g++ -c $(G_FLAGZ) $< -o $@

libninage.a: $(OBJECTS)
	ar rcs $@ $^

libninage.so: $(OBJECTS)
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
	-rm src/*.o
	-rm src/utils/*.o

	cd src/lib/ResourceManager && make clean
