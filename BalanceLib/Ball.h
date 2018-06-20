
/********************************
#   Balancing Ball              #
#   Ball.h                      #
#                               #
#   Authors:                    #
#       KEMPERLE Andreas        #
#       NEUHOLD  Michaela       #
#       SOUKUP   Jakob          #
#       WINKLER  Andreas        #
#                               #
#   created: 2018/06/05         #
#   Version: 2018/06/06 - V1.1  #
********************************/

#pragma once

#include "Enums.h"

// ===============================================================
// BALL CLASS

class Ball
{
public:
	Ball();
	
	double get_position(void) const;
	void set_position(double position);
	double get_velocity(void) const;
	void set_velocity(double velocity);
	void push(Push direction, double velocity);

private:
	double position_;
	double velocity_;
};

