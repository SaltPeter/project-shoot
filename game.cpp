#include "game.h"
#include "graphics.h"
#include "animated_sprite.h"
#include <stdio.h>
#include <SDL/SDL.h>

namespace {
const int HZ = 200;
}

int Game::kTileSize = 32;

Game::Game(){
SDL_Init(SDL_INIT_EVERYTHING);
SDL_ShowCursor(SDL_DISABLE);
//screen_
eventLoop();
}

Game::~Game(){
//freesurface
SDL_Quit();
}

void Game::draw(Graphics& graphics){
sprite_ -> draw(graphics, 320, 240);
graphics.flip();
}

void Game::eventLoop(){
Graphics graphics;
SDL_Event event;

sprite_.reset(new AnimatedSprite(
        "assets/MyChar.bmp", 0, 0, kTileSize, kTileSize, 15, 3));

bool running = true;
int last_update_time = SDL_GetTicks();

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
    const int current_time_ms = SDL_GetTicks();

    update(current_time_ms - last_update_time);

    last_update_time = current_time_ms;

    draw(graphics);

    const int elapsed_time_ms = SDL_GetTicks() - start_time_ms;
    SDL_Delay(1000 / HZ - elapsed_time_ms);
    const float seconds_per_frame = (SDL_GetTicks() - start_time_ms) / 1000.0;
    const float fps = 1 / seconds_per_frame;
    printf("fps=%f\n", fps);
    }
}

void Game::update(int elapsed_time_ms){
sprite_ -> update(elapsed_time_ms);
}


