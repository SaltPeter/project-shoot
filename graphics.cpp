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
SDL_FreeSurface(screen_);
}

void Graphics::blitSurface(SDL_Surface* source,
                 SDL_Rect* source_rect,
                 SDL_Rect* destination_rect){
SDL_BlitSurface(source, source_rect, screen_, destination_rect);
}
