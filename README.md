# Scenengine
> Engine for interactive media & games.

## Development
> To make it easier to work on the core engine / lib, you can run
> the `develop.sh` script.

        ./develop.sh

> The `develop.sh` script will do the following:
* Compile and install the `core engine`
* Compile and launch the `testgame`

> You may use the `testgame` to test changes made in the `core engine`.
> It does not matter if you push changes made in the `testgame` since it
> was created for testing purposes.

## Getting started
> Run the following commands:

        git submodule init
        git submodule update
        git submodule sync

> This will setup the project and make sure you have everything.

> Now to compile and install the engine:

        cd libscenengine
        sudo make install

> This will install the engine into your system / computer.

## Compiling the testgame
> To compile the testgame, make sure you have installed the engine first,
> following the steps above.

> Run these commands to compile and start the testgame:

        cd testgame
        make
        ./game.out

> The game should be up and running.
