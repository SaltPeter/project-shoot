#ifndef GRAPHICS_H_INCLUDED
#define GRAPHICS_H_INCLUDED

struct SDL_Surface;
struct SDL_Rect;

class Graphics{
public:
Graphics();
~Graphics();

void blitSurface(SDL_Surface* source,
                 SDL_Rect* source_rect,
                 SDL_Rect* destination_rect);

void flip();

private:
SDL_Surface* screen_;
};

#endif // GRAPHICS_H_INCLUDED
