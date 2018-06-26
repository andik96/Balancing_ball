
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
#   Version: 2018/06/25 - V2.2  #
********************************/

#pragma once

// ===============================================================
// INCLUDES

#include "Pid.h"
#include "Controller.h"
#include "using_types.h"


// ===============================================================
// CONSTANT EXPRESSIONS

constexpr elapsed watch_time = 100000;		// how long the optimizer shall test every p, i and d combination (in ms)


// ===============================================================
// OPTIMIZER STRUCT

struct Opt_param
{
	double kp_start = 1;
	double ki_start = 0.1;
	double kd_start = 0.5;

	steps k_steps = 10;
};


// #################################### SECTION BREAK ####################################


// ===============================================================
// PID OPTIMIZER CLASS

class Pid_optimizer
{
public:
	Pid get_optimum(Opt_param& opt_param);

private:
	void run(Opt_param& opt_param);
	// ------------ ------------ ------------
	double watch_error(Controller& controller) const;
	// ------------ ------------ ------------
	void try_kp(Controller& controller, Pid& actual_pid, Opt_param& opt_param, steps act_step);
	void try_ki(Controller& controller, Pid& actual_pid, Opt_param& opt_param, steps act_step);
	void try_kd(Controller& controller, Pid& actual_pid, Opt_param& opt_param, steps act_step);
	// ============ ============ ============
	Pid actual_pid_;
	Pid optimal_pid_;
};

