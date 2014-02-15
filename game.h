#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <boost/scoped_ptr.hpp>
// BOOST 1.48
// http://www.boost.org/users/history/version_1_48_0.html
struct Player;
struct Graphics;

class Game{
public:
Game();
~Game();

static int kTileSize;

private:
void draw(Graphics& graphics);
void eventLoop();
void update(int elapsed_time_ms);

boost::scoped_ptr<Player> player_;
};


#endif // GAME_H_INCLUDED

