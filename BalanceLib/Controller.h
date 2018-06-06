#pragma once

#include "using_types.h"
#include "Ball.h"
#include "Beam.h"

class Controller
{
public:
	Controller(Ball ball, Beam beam, double kp, double ki, double kd);


private:
	Ball ball_();
	Beam beam_();
	double kp_;
	double ki_;
	double kd_;
	double desired_position_;
	uint_fast64_t time_passed_; //TODO: Datentyp!!!
};

