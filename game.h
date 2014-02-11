#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

struct SDL_Surface;

class Game{
public:
Game();
~Game();
private:
void draw();
void eventLoop();
void update();

SDL_Surface* screen_;
};


#endif // GAME_H_INCLUDED

