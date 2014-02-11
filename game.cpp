#include "game.h"
#include <stdio.h>
#include <SDL/SDL.h>

namespace {
const int screenWidth = 640;
const int screenHeight = 480;
const int screenBPP = 32;
const int HZ = 60;
}

Game::Game(){
SDL_Init(SDL_INIT_EVERYTHING);
SDL_ShowCursor(SDL_DISABLE);
screen_ = SDL_SetVideoMode(screenWidth, screenHeight, screenBPP, SDL_SWSURFACE);
eventLoop();
}

Game::~Game(){
SDL_FreeSurface(screen_);
SDL_Quit();
}

void Game::draw(){
}

void Game::eventLoop(){
SDL_Event event;
bool running = true;
    while(running){
    const int start_time_ms = SDL_GetTicks();
        while(SDL_PollEvent(&event)){
            switch(event.type){
            case SDL_KEYDOWN:
                if(event.key.keysym.sym == SDLK_ESCAPE)
                    running = false;
            default:
            break;
            }
        }
    update();
    draw();
    const int elapsed_time_ms = SDL_GetTicks() - start_time_ms;
    SDL_Delay(1000 / HZ - elapsed_time_ms);
    const float seconds_per_frame = (SDL_GetTicks() - start_time_ms) / 1000.0;
    const float fps = 1 / seconds_per_frame;
    printf("fps=%f\n", fps);
    }
}

void Game::update(){
}


