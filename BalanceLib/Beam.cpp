
/********************************
#   Balancing Ball              #
#   Beam.cpp                    #
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


// ===============================================================
// INCLUDES

#include "Beam.h"
#include <stdexcept>


// ===============================================================
// INCLUDES

constexpr double max_ang_velocity = double(45)/1000;		// maximum agular velocity in degrees per millisecond (/1000: milliseconds->seconds)
constexpr double max_angle = 22.5;							// maximum angle in degrees


// #################################### SECTION BREAK ####################################


// ===============================================================
// CONSTRUCTOR (and initialiser list)

Beam::Beam(const double length, const double angle, const double ang_velocity) :
length_(length), angle_(angle), ang_velocity_(ang_velocity)
{
}


// #################################### SECTION BREAK ####################################


// ===============================================================
// GET LENGHT OF BEAM

double Beam::get_lenght() const
{
	return this->length_;
}


// ===============================================================
// GET CURRENT BEAM ANGLE

double Beam::get_angle() const
{
	return this->angle_;
}

// ===============================================================
// SET CURRENT BEAM ANGLE

void Beam::set_angle(const double angle, const elapsed time_elapsed)
{
	// --- CALCULATE ANGULAR VELOCITY ---

	if(time_elapsed > 0)													// valid time change
		this->ang_velocity_ = (angle - this->angle_)/time_elapsed;
	else
		throw std::runtime_error("Invalid elapsed time!");


	// --- ANGULAR VELOCITY LIMIT ---

	if(this->ang_velocity_ < max_ang_velocity && this->ang_velocity_ > -max_ang_velocity)		// angle velocity in possible range
		this->angle_ = angle; 
	else if(angle > this->angle_)											// angular velocity is positive
		this->angle_ = this->angle_ + max_ang_velocity*time_elapsed;
	else																	// angular velocity is negative
		this->angle_ = this->angle_ - max_ang_velocity*time_elapsed;


	// --- ANGULAR LIMIT ---

	if(this->angle_ > max_angle)
		this->angle_ = max_angle;
	else if(this->angle_ < -max_angle)
		this->angle_ = -max_angle;
}