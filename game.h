#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <boost/scoped_ptr.hpp>
// BOOST 1.48
// http://www.boost.org/users/history/version_1_48_0.html

class Game{
public:
Game();
~Game();
private:
void draw();
void eventLoop();
void update();

boost::scoped_ptr<Sprite> sprite_;
};


#endif // GAME_H_INCLUDED

