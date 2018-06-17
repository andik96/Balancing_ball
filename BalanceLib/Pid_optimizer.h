
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
#   Version: 2018/06/11 - V1.0  #
********************************/

#pragma once

// ===============================================================
// INCLUDES

#include "Controller.h"


// ===============================================================
// PID STRUCT

struct Pid_data
{
	double kp_ = 1;
	double ki_ = 0;
	double kd_ = 0;

	double error = 0;
};


// #################################### SECTION BREAK ####################################


// ===============================================================
// PID OPTIMIZER CLASS

class Pid_optimizer
{
public:
	void run(Controller& my_controller);
	Pid_data get_optimum();

private:
	Pid_data actual_pid_data_;
	Pid_data optimal_pid_data_;
	Controller& my_controller_;
};

