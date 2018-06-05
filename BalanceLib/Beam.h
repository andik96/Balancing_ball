
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


// ===============================================================
// INCLUDES

#include "IBeam.h"


// #################################### SECTION BREAK ####################################


// ===============================================================
// BEAM CLASS

class Beam : public IBeam
{
public:

	Beam();
	Beam(double length, double angle, double ang_velocity);
	~Beam() = default;

	// neither copy or move constructors or operators will be used
	Beam(const Beam &other) = delete;
	Beam(const Beam &&other) = delete;
	Beam &operator = (const Beam& other) = delete;
	Beam &&operator = (const Beam&& other) = delete;

	// --------- --------- --------- ---------
	double get_lenght(void) const override;
	void set_lenght(const double lenght) override;
	// --------- --------- --------- ---------
	double get_angle(void) const override;
	void set_angle(const double angle) override;
	// --------- --------- --------- ---------
	double get_ang_velocity(void) const override;
	void set_ang_velocity(const double ang_velocity) override;
	// --------- --------- --------- ---------

private:
	double length_;
	double angle_;
	double ang_velocity_;
};