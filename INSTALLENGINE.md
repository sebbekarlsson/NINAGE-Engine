# Installing the Engine
> These are the steps of installing the NINAGE engine
> onto your system.

## Linux
* Make sure you have all the [requirements](REQUIREMENTS.md)
* Compile and install the engine:

        sudo make install

> This will compile all the source files and place [libninage.so, libninage.o]
> in */usr/local/lib*

> It will also copy necessary header files (.h) in */usr/local/include*

## OSX / Mac
* Make sure you have all the [requirements](REQUIREMENTS.md)
* Compile and install using the same instructions as above, for some reason,
  sudo is not needed on OSX / Mac.
