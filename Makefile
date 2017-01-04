FLAGZ = `pkg-config --libs sdl2` -lGL -lglut -lSDL2_image -lSDL2_ttf -lGLU -g

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
	g++ $(FLAGZ) -c src/main.cpp

SDLOpenGL.o: src/engine/SDLOpenGL.cpp src/engine/SDLOpenGL.h
	g++ $(FLAGZ) -c src/engine/SDLOpenGL.cpp

Sprite.o: src/engine/Sprite.cpp src/engine/Sprite.h
	g++ $(FLAGZ) -c src/engine/Sprite.cpp

Instance.o: src/engine/Instance.cpp src/engine/Instance.h
	g++ $(FLAGZ) -c src/engine/Instance.cpp

TestObj.o: src/engine/TestObj.cpp src/engine/TestObj.h
	g++ $(FLAGZ) -c src/engine/TestObj.cpp

Scene.o: src/engine/Scene.cpp src/engine/Scene.h
	g++ $(FLAGZ) -c src/engine/Scene.cpp

TestScene.o: src/engine/TestScene.cpp src/engine/TestScene.h
	g++ $(FLAGZ) -c src/engine/TestScene.cpp

clean:
	rm *.o
	rm *.out
