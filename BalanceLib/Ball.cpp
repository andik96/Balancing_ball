
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


// ===============================================================
// INCLUDES

#include "Ball.h"
#include <stdexcept>


// #################################### SECTION BREAK ####################################


// ===============================================================
// CONSTRUCTOR (and initialiser list)

Ball::Ball(const double position, const double velocity) : 
position_(position), velocity_(velocity)
{}

// ===============================================================
// DEFAULT CONSTRUCTOR

Ball::Ball() : position_(0), velocity_(0)
{}


// #################################### SECTION BREAK ####################################


// ===============================================================
// GET CURRENT BALL POSITION

double Ball::get_position() const
{
	return this->position_;
}

// ===============================================================
// SET CURRENT BALL POSITION

void Ball::set_position(const double position)
{
	this->position_ = position;
}


// ===============================================================
// GET CURRENT BALL SPEED

double Ball::get_velocity() const
{
	return this->velocity_;
}

// ===============================================================
// SET CURRENT BALL SPEED

void Ball::set_velocity(const double velocity)
{
	this->velocity_ = velocity;
}


// ===============================================================
// PUSH BALL LEFT/RIGHT

void Ball::push(const Push direction)
{
	if(direction == Push::left)
		this->velocity_ -= 0.5;
	else if(direction == Push::right)
		this->velocity_ += 0.5;
	else
		throw std::logic_error ("Only push ball left or right!");
}