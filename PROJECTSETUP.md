# Setting Up a Project
> Instructions for creating an application using NINAGE

## Requirements
> Make sure you have all the [requirements](REQUIREMENTS.md).


## Your Project
### main.cpp
> This is where your app starts.

        #include <ninage/Ninage.h>
        #include "MainScene.h"


        Ninage  *app;
        const Uint8 *state = SDL_GetKeyboardState(NULL); // this is needed for keyboard & mouse input.

        /**
         * This is where the `app` is initialized.
         * Here, you can add scenes for example.
         *
         * This function will run at startup.
        */
        void Ninage::main() {
            MainScene *scene = new MainScene();

            this->addScene(scene);
        }

        int main (int argc, char* args[]) {
            app = new Ninage();
            
            // Start the main loop, will return the state integer when canceled.
            return app->run();
        }

## More Information
> For more information on how to setup a project, please look at the
> [testgame](testgame), or look at the [examples](https://github.com/sebbekarlsson/NINAGE-examples)
