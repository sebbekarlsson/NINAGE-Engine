# NINAGE ENGINE
> **N**inage **I**s **N**ot **A** **G**ame **E**ngine

> ![alt text](77599_vrlrc_engine_sm.gif)

> (But it can be used as a app engine)

> It's purpose is to be an interactive media engine, apps just happen
> to fall into that catagory.

## Documentation
> [Documentation](DOCUMENTATION.md)

## Getting Started
* Make sure you have the [requirements](REQUIREMENTS.md).
> Run the following commands:

        git submodule init
        git submodule update
        git submodule sync

> This will setup the project and make sure you have everything.

## Development
> To make it easier to work on the core engine / lib, you can run
> the `develop.sh` script.

        ./develop.sh

> The `develop.sh` script will do the following:
* Compile and install the `core engine`
* Compile and launch the `testapp`

> You may use the `testapp` to test changes made in the `core engine`.
> It does not matter if you push changes made in the `testapp` since it
> was created for testing purposes.

## Manual Development
### Compiling and installing the engine:

        cd libninage
        sudo make install

> This will install the engine into your system / computer.

### Compiling the testapp
> To compile the testapp, make sure you have installed the engine first,
> following the steps above.

> Run these commands to compile and start the testapp:

        cd testapp
        make
        ./app.out

> The app should be up and running.
