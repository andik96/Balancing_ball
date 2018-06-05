
/********************************
#   Balancing Ball              #
#   IBall.h                     #
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
// INTERFACE FOR CLASS BALL

class IBall
{
public:
	// --------- --------- --------- ---------
	virtual double get_position(void) const = 0;
	virtual void set_position(const double position) = 0;
	// --------- --------- --------- ---------
	virtual double get_velocity(void) const = 0;
	virtual void set_velocity(const double velocity) = 0;
	// --------- --------- --------- ---------
	virtual void push(const Push direction) = 0;
	// --------- --------- --------- ---------

	virtual ~IBall() = 0;
};