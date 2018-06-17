
/********************************
#   Balancing Ball              #
#   Pid_optimizer.cpp           #
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


// ===============================================================
// INCLUDES

#include "Pid_optimizer.h"


// #################################### SECTION BREAK ####################################


// ===============================================================
// RUN OPTIMIZER

void Pid_optimizer::run(Controller& my_controller)
{
	// TODO: PUT OPTIMIZER CODE HERE
}


Pid_data Pid_optimizer::get_optimum()
{
	return this->optimal_pid_data_;
}