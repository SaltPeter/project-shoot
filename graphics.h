#ifndef GRAPHICS_H_INCLUDED
#define GRAPHICS_H_INCLUDED

#include <map>
#include <string>

struct SDL_Surface;
struct SDL_Rect;

class Graphics{
public:
Graphics();
~Graphics();

typedef SDL_Surface* SurfaceID;

SurfaceID loadImage(const std::string &file_path);

void blitSurface(SurfaceID source, SDL_Rect* source_rect, SDL_Rect* destination_rect);

void clear();

void flip();

private:
typedef std::map<std::string, SDL_Surface*> SpriteMap;
SpriteMap sprite_sheets_;
SDL_Surface* screen_;
};

#endif // GRAPHICS_H_INCLUDED
