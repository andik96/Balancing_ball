
/********************************
#   Balancing Ball              #
#   BalanceOptimizer.cpp        #
#                               #
#   Authors:                    #
#       KEMPERLE Andreas        #
#       NEUHOLD  Michaela       #
#       SOUKUP   Jakob          #
#       WINKLER  Andreas        #
#                               #
#   created: 2018/06/25         #
#   Version: 2018/06/25 - V1.0  #
********************************/


// ===============================================================
// INCLUDES

#include "stdafx.h"
#include "../BalanceLib/Pid_optimizer.h"
#include "../BalanceLib/Pid.h"
#include <iostream>


// #################################### SECTION BREAK ####################################


// ===============================================================
// MAIN FUNCTION (run this to get the optimal pid settings)
// ===============================================================

int main()
{
	Opt_param opt_param;
	opt_param.kp_start = 1;
	opt_param.ki_start = 0;
	opt_param.kd_start = 0;

	Pid_optimizer pid_optimizer;

	const Pid optimal_pid = pid_optimizer.get_optimum(opt_param);

	std::cout << "\n\t Found ideal PID controller settings:\n" << 
		"\n\t\t\t kp: " << optimal_pid.kp <<
		"\n\t\t\t ki: " << optimal_pid.ki <<
		"\n\t\t\t kd: " << optimal_pid.kd <<
		"\n\n\t relative error: " << optimal_pid.error << std::endl;

	getchar();
	getchar();

    return 0;
}