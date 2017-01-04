FLAGZ = `pkg-config --libs sdl2` -lGL -lglut -lSDL2_image -lSDL2_ttf -lGLU -g

output:\
    main.o\
    SDLOpenGL.o
	g++ $(FLAGZ)\
	    main.o\
	    SDLOpenGL.o\
	    -o game.out

main.o: src/main.cpp
	g++ $(FLAGZ) -c src/main.cpp

SDLOpenGL.o: src/engine/SDLOpenGL.cpp src/engine/SDLOpenGL.h
	g++ $(FLAGZ) -c src/engine/SDLOpenGL.cpp

clean:
	rm *.o
	rm *.out
