#include "Controller.h"
#include <chrono>
#include "Clock.h"


Controller::Controller(Ball ball, Beam beam, double kp, double ki, double kd) : ball_{ ball }, beam_{ beam }, kp_{ kp }, ki_{ ki }, kd_{ kd }
{
}

double Controller::control(double position, elapsed current_time)
{
	static elapsed previous_time = current_time - 10;
	elapsed time_passed = current_time - previous_time;

	static double e_sum = 0;
	static double e_old = 0;

	double e = desired_position_ - position;
	e_sum = e_sum + e;

	double desired_angle = kp_ * e + ki_ * time_passed * e_sum + kd_ * (e - e_old) / time_passed;
	e_old = e;

	previous_time = current_time;
	return desired_angle;
}

void Controller::update(double desired_angle)  //elapsed current_time
{
	//TODO: delete: static elapsed previous_time = current_time -10;	//ohne static funktionierts
	//TODO: delete: elapsed time_passed = current_time - previous_time;	
	elapsed previous_time = clock_.timestamp_update_;
	elapsed time_passed = clock_.get_time() - previous_time;

	beam_.set_angle(desired_angle, time_passed);

	static constexpr double g = 9.80665;
	static constexpr double pi = 3.14159265;
	double velocity_calc = g * sin(beam_.get_angle()*pi/180) * time_passed;  //in m/ms
	ball_.set_velocity(velocity_calc + ball_.get_velocity());
	
	//TODO: delete: previous_time = current_time;
	clock_.timestamp_update_ = clock_.get_time();
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

 //Controller::get_time() const
//{
//	elapsed time;
//	#if _WIN32 || _WIN64
//		auto now = std::chrono::system_clock::now().time_since_epoch();
//		time = std::chrono::duration_cast<std::chrono::milliseconds>(now).count();
//	#else 
//		time = millis();
//	#endif
//
//		return time;
//}
