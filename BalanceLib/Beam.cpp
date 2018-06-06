
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
// SET LENGHT OF BEAM

void Beam::set_lenght(const double lenght)
{
	this->length_ = lenght;
}


// ===============================================================
// GET CURRENT BEAM ANGLE

double Beam::get_angle() const
{
	return this->angle_;
}

// ===============================================================
// SET CURRENT BEAM ANGLE

void Beam::set_angle(const double angle)
{
	this->angle_ = angle;
}


// ===============================================================
// GET CURRENT ANGULAR VELOCITY OF BEAM

double Beam::get_ang_velocity() const
{
	return this->ang_velocity_;
}

// ===============================================================
// SET CURRENT ANGULAR VELOCITY OF BEAM

void Beam::set_ang_velocity(const double ang_velocity)
{
	this->ang_velocity_ = ang_velocity;
}
