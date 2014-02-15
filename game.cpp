#include "game.h"
#include "graphics.h"
#include "player.h"
#include "input.h"
#include <stdio.h>
#include <SDL/SDL.h>

namespace{
const int HZ = 200;
}

int Game::kTileSize = 32;

Game::Game(){
SDL_Init(SDL_INIT_EVERYTHING);
SDL_ShowCursor(SDL_DISABLE);
eventLoop();
}

Game::~Game(){
SDL_Quit();
}

void Game::draw(Graphics& graphics){
graphics.clear();
player_ -> draw(graphics);
graphics.flip();
}

void Game::eventLoop(){
Graphics graphics;
Input input;
SDL_Event event;

player_.reset(new Player(graphics, 320, 240));

bool running = true;
int last_update_time = SDL_GetTicks();

    while(running){ /// WHILE(RUNNING) LOOP
    const int start_time_ms = SDL_GetTicks();
    input.beginNewFrame();
        while(SDL_PollEvent(&event)){
            switch(event.type){
            case SDL_KEYDOWN:
            input.keyDownEvent(event);
            break;
            case SDL_KEYUP:
            input.keyUpEvent(event);
            break;
            default:
            break;
            }
        }

    if(input.wasKeyPressed(SDLK_ESCAPE)){
    running = false;
    }
    if(input.isKeyHeld(SDLK_LEFT) && input.isKeyHeld(SDLK_RIGHT)){
    player_ -> stopMoving();
    }
    else if(input.isKeyHeld(SDLK_LEFT)){
    player_ -> startMovingLeft();
    }
    else if(input.isKeyHeld(SDLK_RIGHT)){
    player_ -> startMovingRight();
    }
    else{
    player_ -> stopMoving();
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
    } /// WHILE(RUNNING) LOOP
} /// GAME::EVENTLOOP() MEMBER FUNCTION

void Game::update(int elapsed_time_ms){
player_ -> update(elapsed_time_ms);
}
