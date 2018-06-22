
/********************************
#   Balancing Ball              #
#   Pid.h                       #
#                               #
#   Authors:                    #
#       KEMPERLE Andreas        #
#       NEUHOLD  Michaela       #
#       SOUKUP   Jakob          #
#       WINKLER  Andreas        #
#                               #
#   created: 2018/06/21         #
#   Version: 2018/06/21 - V1.0  #
********************************/

#pragma once


// ===============================================================
// PID STRUCT

struct Pid
{
	double kp = 1;
	double ki = 0;
	double kd = 0;

	double error = 0;
};