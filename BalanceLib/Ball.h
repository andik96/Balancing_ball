
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


// ===============================================================
// ENUM CLASS FOR PUSHING BALL

enum class Push
{
	left,
	right
};


// #################################### SECTION BREAK ####################################


// ===============================================================
// BALL CLASS

class Ball
{
public:

	Ball(double position = 0, double velocity = 0);

	// --------- --------- --------- ---------
	double get_position(void) const;
	void set_position(const double position);
	// --------- --------- --------- ---------
	double get_velocity(void) const;
	void set_velocity(const double velocity);
	// --------- --------- --------- ---------
	void push(const Push direction, const double velocity);
	// --------- --------- --------- ---------

private:
	double position_;
	double velocity_;
};

