#pragma once

#include "using_types.h"
#include "Ball.h"
#include "Beam.h"

class Controller
{
public:
	Controller(Ball ball, Beam beam, double kp, double ki, double kd);
	double control(double position);
	void update(double desired_angle);
	double get_kp() const;
	void set_kp(double kp);
	double get_ki() const;
	void set_ki(double ki);
	double get_kd() const;
	void set_kd(double ki);

	Ball ball_;
	Beam beam_;

private:
	double kp_;
	double ki_;
	double kd_;
	double desired_position_;
};

