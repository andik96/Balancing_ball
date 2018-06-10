#pragma once

#include "using_types.h"
#include "Ball.h"
#include "Beam.h"

class Controller
{
public:
	Controller(Ball ball, Beam beam, double kp, double ki, double kd);
	double control(double position);
	void update(double angle, elapsed time_passed);

private:
	Ball ball_();
	Beam beam_();
	double kp_;
	double ki_;
	double kd_;
	double desired_position_;
	elapsed time_passed_;
};

