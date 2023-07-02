#ifndef GAME_H
#define GAME_H
#define SDL_MAIN_HANDLED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "./Entity.h"
#include "./Component.h"
#include "./EntityManager.h"

class Game {
    private:
        bool isRunning;
        SDL_Window *window;

    public:
        Game();
        ~Game();
        bool IsRunning() const;
        bool ticksLastFrame = 0;
        static SDL_Renderer *renderer;
        void LoadLevel(int levelNumber);
        void Initialize(int width,int height);
        void ProcessInput();
        void Update();
        void Render();
        void Destroy();
};

#endif