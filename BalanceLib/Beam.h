
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
#   Version: 2018/06/06 - V1.1  #
********************************/

#pragma once


// ===============================================================
// INCLUDES

#include "using_types.h"



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
	void set_angle(const double angle, const elapsed time_elapsed);
	// --------- --------- --------- ---------

private:
	double length_;
	double angle_;
	double ang_velocity_;
};