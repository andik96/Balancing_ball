
/********************************
#   Balancing Ball              #
#   Ball.cpp                    #
#                               #
#   Authors:                    #
#       KEMPERLE Andreas        #
#       NEUHOLD  Michaela       #
#       SOUKUP   Jakob          #
#       WINKLER  Andreas        #
#                               #
#   created: 2018/06/05         #
#   Version: 2018/06/05 - V1.0  #
********************************/

#include "Ball.h"

Ball::Ball():position_{0},velocity_{0}
{
}

double Ball::get_position(void) const
{
	return position_;
}

void Ball::set_position(double position)
{
	position_ = position;
}

double Ball::get_velocity(void) const
{
	return velocity_;
}

void Ball::set_velocity(double velocity)
{
	velocity_ = velocity;
}

void Ball::push(Push direction, double velocity)
{
	if (direction == Push::left)
		velocity_ -= velocity;
	if (direction == Push::right)
		velocity_ += velocity;
}
