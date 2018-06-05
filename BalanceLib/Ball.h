
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
#   Version: 2018/06/05 - V1.0  #
********************************/

#pragma once


// ===============================================================
// INCLUDES

#include "IBall.h"


// #################################### SECTION BREAK ####################################


// ===============================================================
// BALL CLASS

class Ball : public IBall
{
public:

	Ball();
	Ball(double position, double velocity);
	~Ball() = default;

	// neither copy or move constructors or operators will be used
	Ball(const Ball &other) = delete;
	Ball(const Ball &&other) = delete;
	Ball &operator = (const Ball& other) = delete;
	Ball &&operator = (const Ball&& other) = delete;

	// --------- --------- --------- ---------
	double get_position(void) const override;
	void set_position(const double position) override;
	// --------- --------- --------- ---------
	double get_velocity(void) const override;
	void set_velocity(const double velocity) override;
	// --------- --------- --------- ---------
	void push(const Push direction) override;
	// --------- --------- --------- ---------

private:
	double position_;
	double velocity_;
};
