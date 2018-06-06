
/********************************
#   Balancing Ball              #
#   Beam.h                      #
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


// #################################### SECTION BREAK ####################################


// ===============================================================
// BEAM CLASS

class Beam
{
public:

	Beam(double length = 2, double angle = 0, double ang_velocity = 0);

	// --------- --------- --------- ---------
	double get_lenght(void) const;
	// --------- --------- --------- ---------
	double get_angle(void) const;
	void set_angle(const double angle);
	// --------- --------- --------- ---------
	double get_ang_velocity(void) const;
	void set_ang_velocity(const double ang_velocity);
	// --------- --------- --------- ---------

private:
	double length_;
	double angle_;
	double ang_velocity_;
};