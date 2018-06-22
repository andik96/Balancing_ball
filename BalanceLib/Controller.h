#pragma once

#include "using_types.h"
#include "Pid.h"
#include "Ball.h"
#include "Beam.h"

class Controller
{
public:
	Controller(Ball& ball, Beam& beam, Pid& pid_data);
	double control(double position);
	// void update(double desired_angle);

	double run();
	elapsed get_time();

	double get_kp() const;
	void set_kp(double kp);
	double get_ki() const;
	void set_ki(double ki);
	double get_kd() const;
	void set_kd(double kd);

	Ball ball_;
	Beam beam_;

private:
	Pid pid_data_;
	const double desired_position_ = 0;
	elapsed time_last_call_ = 0;


#if _WIN32 || _WIN64
	elapsed act_time_ = 0;
#endif
};

