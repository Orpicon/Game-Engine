#include <iostream>
#include "Constants.h"
#include "Game.h"
#include "EntityManager.h"
#include "../lib/glm/glm.hpp"

EntityManager manager;
SDL_Renderer* Game::renderer;

Game::Game(){
    this->isRunning = false;
}

Game::~Game() {

}

bool Game::IsRunning() const{
    return this->isRunning;
}

void Game::Initialize(int width, int height){
    if(SDL_Init(SDL_INIT_EVERYTHING)!=0){
        std::cerr<<"Error initializing SDL."<<std::endl;
        return;
    }
    window = SDL_CreateWindow(NULL,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_BORDERLESS);
    if(!window){
        std::cerr<<"Error initializing Window."<<std::endl;
        return;
    }
    renderer = SDL_CreateRenderer(window, -1, 0);
    if(!renderer){
        std::cerr<<"Error initializing renderer."<<std::endl;
        return;
    }
    isRunning = true;
    return;
}

void Game::ProcessInput(){
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type){
        case SDL_QUIT:
            isRunning = false;
            break;
        case SDL_KEYDOWN:
            if(event.key.keysym.sym == SDLK_ESCAPE){
                isRunning = false;
            }
        default:
            break;

    }
}

void Game::Update(){
     // Wait until 16ms has ellapsed since the last frame
    while (!SDL_TICKS_PASSED(SDL_GetTicks(), ticksLastFrame + FRAME_TARGET_TIME));
    
    // Delta time is the difference in ticks from last frame converted to secomds
    float deltaTime = (SDL_GetTicks() - ticksLastFrame) / 1000.0f;

    // Clamp deltaTime to a maximum value
    deltaTime = (deltaTime > 0.05f) ? 0.05f : deltaTime;

    // Sets the new ticks for the current frame to be used in the next pass
    ticksLastFrame = SDL_GetTicks();

   
    // Use deltaTime to update my game objects
    
}

void Game::Render(){
    SDL_SetRenderDrawColor(renderer, 21,21,21,255);
    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);
}

void Game::Destroy(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}