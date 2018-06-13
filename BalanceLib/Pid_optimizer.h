
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

//#include "Pid_controller.h"


// ===============================================================
// PID STRUCT

struct Pid
{
	double kp_ = 1;
	double ki_ = 0;
	double kd_ = 0;
};


// #################################### SECTION BREAK ####################################


// ===============================================================
// PID OPTIMIZER CLASS
//
//class Pid_optimizer
//{
//public:
//	void run(Pid_controller& my_controller);
//	// struct Pid get_optimum();
//
//private:
//	// Pid pid_opt_data_;
//	Pid_controller& my_controller;
//};

