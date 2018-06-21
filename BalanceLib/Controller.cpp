#include "Controller.h"


Controller::Controller(Ball ball, Beam beam, double kp, double ki, double kd) : ball_{ ball }, beam_{ beam }, kp_{ kp }, ki_{ ki }, kd_{ kd }, desired_position_{ 0 }
{
}

double Controller::control(double position)
{
	static constexpr elapsed simulated_time = 1000;

	elapsed time_passed = simulated_time;
	static double e_sum = 0;
	static double e_old = 0;

	double e = desired_position_ - position;
	e_sum = e_sum + e;

	double desired_angle = kp_ * e + ki_ * time_passed/1000 * e_sum + kd_ * (e - e_old) / (time_passed/1000);
	e_old = e;

	return desired_angle;
}

void Controller::update(double desired_angle)  
{
	static constexpr elapsed simulated_time = 1000;

	elapsed time_passed = simulated_time;

	beam_.set_angle(desired_angle, time_passed);

	static constexpr double g = 9.80665;
	static constexpr double pi = 3.14159265;
	double velocity_calc = g * sin(beam_.get_angle()*pi/180) * time_passed/1000;  //in m/s
	ball_.set_velocity(velocity_calc + ball_.get_velocity());
}

double Controller::get_kp() const
{
	return kp_;
}

void Controller::set_kp(double kp)
{
	kp_ = kp;
}

double Controller::get_ki() const
{
	return ki_;
}

void Controller::set_ki(double ki)
{
	ki_ = ki;
}

double Controller::get_kd() const
{
	return kd_;
}

void Controller::set_kd(double kd)
{
	kd_ = kd;
}
