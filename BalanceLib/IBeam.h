
/********************************
#   Balancing Ball              #
#   IBeam.h                     #
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
// INTERFACE FOR CLASS BEAM

class IBeam
{
public:
	// --------- --------- --------- ---------
	virtual double get_lenght(void) const = 0;
	virtual void set_lenght(const double lenght) = 0;
	// --------- --------- --------- ---------
	virtual double get_angle(void) const = 0;
	virtual void set_angle(const double angle) = 0;
	// --------- --------- --------- ---------
	virtual double get_ang_velocity(void) const = 0;
	virtual void set_ang_velocity(const double ang_velocity) = 0;
	// --------- --------- --------- ---------

	virtual ~IBeam() = 0;
};