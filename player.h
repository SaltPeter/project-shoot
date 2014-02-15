#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "sprite.h"
#include <boost/shared_ptr.hpp>
#include <map>

struct Sprite;
struct Graphics;

class Player{
public:
Player(Graphics &graphics, int x, int y);

void update(int elapsed_time_ms);
void draw(Graphics &graphics);
void startMovingLeft();
void startMovingRight();
void stopMoving();

private:
enum MotionType{
STANDING, WALKING
};
enum HorizontalFacing{
LEFT, RIGHT
};

class SpriteState{
public:
SpriteState(MotionType motion_type = STANDING, HorizontalFacing horizontal_facing = LEFT)
: motion_type(motion_type), horizontal_facing(horizontal_facing){
}
MotionType motion_type;
HorizontalFacing horizontal_facing;
};

friend bool operator<(const SpriteState &a, const SpriteState &b);

void initializeSprites(Graphics &graphics);

SpriteState getSpriteState();

int x_, y_;
float velocity_x_;
float acceleration_x_;
HorizontalFacing horizontal_facing_;
std::map<SpriteState, boost::shared_ptr<Sprite> > sprites_;
};


#endif // PLAYER_H_INCLUDED
