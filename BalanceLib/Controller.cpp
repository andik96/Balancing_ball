#include "Controller.h"

constexpr double g = 9.80665;
constexpr double pi = 3.14159265;

constexpr elapsed simulated_time = 1000;			// for windows



Controller::Controller(Ball& ball, Beam& beam, Pid pid_data) : 
ball_{ ball }, beam_{ beam }, pid_data_(pid_data), desired_position_{ 0 }
{
}

double Controller::control(double position)
{
	// ================================================
	// =============== TIME MANAGEMENT ================
	// ================================================

	static elapsed time_last_call = 0;

#if _WIN32 || _WIN64										// WINDOWS
	this->act_time_ = this->get_time();
	auto time_passed = this->act_time_ - time_last_call;
	time_last_call = this->act_time_;
#else														// RASPBERRY
	auto time_passed = this->get_time() - time_last_call;
	time_last_call = this->get_time();
#endif


	// ================================================
	// ================ PID CONTROLLER ================
	// ================================================

	static double e_sum = 0;
	static double e_old = 0;

	double e = desired_position_ - position;
	e_sum = e_sum + e;

	double desired_angle = pid_data_.kp * e + pid_data_.ki * time_passed/1000 * e_sum + pid_data_.kd * (e - e_old) / (time_passed/1000);
	e_old = e;

	return desired_angle;
}

/*
void Controller::update(double desired_angle)  
{
#if _WIN32 || _WIN64								// WINDOWS
	elapsed time_passed = simulated_time;
#else												// RASPBERRY
	elapsed time_passed = millis();
#endif

	beam_.set_angle(desired_angle, time_passed);

	static constexpr double g = 9.80665;
	static constexpr double pi = 3.14159265;
	double velocity_calc = g * sin(beam_.get_angle()*pi/180) * time_passed/1000;  //in m/s
	ball_.set_velocity(velocity_calc + ball_.get_velocity());
}*/



double Controller::run(void)
{
	static elapsed time_last_call = 0;


	// =============== TIME MANAGEMENT ================

#if _WIN32 || _WIN64										// WINDOWS
	this->act_time_ = this->get_time();
	auto time_passed = this->act_time_ - time_last_call;
	time_last_call = this->act_time_;
#else														// RASPBERRY
	auto time_passed = this->get_time() - time_last_call;
	time_last_call = this->get_time();
#endif


	// =============== CONTROL BALL AND BEAM ================

	this->beam_.set_angle(this->control(this->ball_.get_position()), time_passed);

	double velocity_calc = g * sin(this->beam_.get_angle()*pi / 180) * time_passed / 1000;  //in m/s
	this->ball_.set_velocity(velocity_calc + this->ball_.get_velocity());

	return this->ball_.get_position();
}


elapsed Controller::get_time(void)
{
#if _WIN32 || _WIN64							// WINDOWS
	this->act_time_ += simulated_time;
	return this->act_time_;
#else											// RASPBERRY
	return millis();
#endif
}



double Controller::get_kp() const
{
	return this->pid_data_.kp;
}

void Controller::set_kp(double kp)
{
	this->pid_data_.kp = kp;
}

double Controller::get_ki() const
{
	return this->pid_data_.ki;
}

void Controller::set_ki(double ki)
{
	this->pid_data_.ki = ki;
}

double Controller::get_kd() const
{
	return this->pid_data_.kd;
}

void Controller::set_kd(double kd)
{
	this->pid_data_.kd = kd;
}
