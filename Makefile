FLAGZ = `pkg-config --libs sdl2` -lGL -lglut -lSDL2_image -lSDL2_ttf -lGLU -g

output:\
    src/main.o\
    src/SDLOpenGL.o
	g++ $(FLAGZ)\
	    src/main.o\
	    src/SDLOpenGL.o\
	    -o game.out

main.o: src/main.cpp
	g++ $(FLAGZ) -c src/main.cpp

SDLOpenGL.o: src/SDLOpenGL.cpp SDLOpenGL.h
	g++ $(FLAGZ) -c src/SDLOpenGL.cpp

clean:
	rm src/*.o
	rm *.out
