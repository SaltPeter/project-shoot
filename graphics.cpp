#include "graphics.h"
#include <SDL/SDL.h>

namespace{
const int screenWidth = 640;
const int screenHeight = 480;
const int screenBPP = 32;
}

Graphics::Graphics(){
screen_ = SDL_SetVideoMode(screenWidth, screenHeight, screenBPP, SDL_SWSURFACE);
}

Graphics::~Graphics(){
    for(SpriteMap::iterator iter = sprite_sheets_.begin(); iter != sprite_sheets_.end(); ++iter){
    SDL_FreeSurface(iter -> second);
    }
SDL_FreeSurface(screen_);
}

Graphics::SurfaceID Graphics::loadImage(const std::string &file_path){
    if(sprite_sheets_.count(file_path) == 0){
    sprite_sheets_[file_path] = SDL_LoadBMP(file_path.c_str());
        if(sprite_sheets_[file_path] == NULL){
        fprintf(stderr, "Could not find image: %s\n", file_path.c_str());
        exit(EXIT_FAILURE);
        }
    }
return sprite_sheets_[file_path];
}

void Graphics::blitSurface(SurfaceID source, SDL_Rect* source_rect, SDL_Rect* destination_rect){
SDL_BlitSurface(source, source_rect, screen_, destination_rect);
}

void Graphics::clear(){
SDL_FillRect(screen_, NULL /*destination_rect*/, 0/*Uint32 color*/);
}

void Graphics::flip(){
SDL_Flip(screen_);
}
