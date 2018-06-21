
/********************************
#   Balancing Ball              #
#   Pid_optimizer.h             #
#                               #
#   Authors:                    #
#       KEMPERLE Andreas        #
#       NEUHOLD  Michaela       #
#       SOUKUP   Jakob          #
#       WINKLER  Andreas        #
#                               #
#   created: 2018/06/11         #
#   Version: 2018/06/21 - V2.1  #
********************************/

#pragma once

// ===============================================================
// INCLUDES

#include "Pid.h"
#include "Controller.h"
#include "using_types.h"


// ===============================================================
// CONSTANT EXPRESSIONS

constexpr elapsed watch_time = 10000;		// how long the optimizer shall test every p, i and d combination (in ms)


// ===============================================================
// OPTIMIZER STRUCT

struct Optimizer
{
	double kp_start = 1;
	double ki_start = 0.1;
	double kd_start = 0.05;

	steps k_steps = 10;
};


// #################################### SECTION BREAK ####################################


// ===============================================================
// PID OPTIMIZER CLASS

class Pid_optimizer
{
public:
	void run(Controller& my_controller, Optimizer& optimizer_data);
	// ------------ ------------ ------------
	Pid get_optimum() const;

private:
	double watch_error(Controller& my_controller) const;
	// ============ ============ ============
	Pid actual_pid_;
	Pid optimal_pid_;

};

