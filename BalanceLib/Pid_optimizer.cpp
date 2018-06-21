
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
#   Version: 2018/06/11 - V2.1  #
********************************/


// ===============================================================
// INCLUDES

#include "Pid_optimizer.h"


// #################################### SECTION BREAK ####################################


// ===============================================================
// RUN OPTIMIZER

void Pid_optimizer::run(Controller& my_controller, Optimizer& optimizer_data)
{
	// ========= INITIALIZE P, I, D =========
	actual_pid_.kp = optimizer_data.kp_start;
	actual_pid_.ki = optimizer_data.ki_start;
	actual_pid_.kd = optimizer_data.kd_start;

	my_controller.set_kp(actual_pid_.kp);
	my_controller.set_ki(actual_pid_.ki);
	my_controller.set_kd(actual_pid_.kd);


	for (steps act_step = 0; act_step < optimizer_data.k_steps; act_step++)
	{
		// ================================================
		// ====================== P =======================
		// ================================================

		actual_pid_.kp += optimizer_data.kp_start / (2 ^ act_step);
		my_controller.set_kp(actual_pid_.kp);

		actual_pid_.error = this->watch_error(my_controller);

		if (actual_pid_.error < optimal_pid_.error)
		{
			optimal_pid_.kp = actual_pid_.kp;
			optimal_pid_.error = actual_pid_.error;
		}
		else
			actual_pid_.kp -= optimizer_data.kp_start / (2 ^ act_step);

		my_controller.set_kp(actual_pid_.kp);


		// ================================================
		// ====================== I =======================
		// ================================================

		actual_pid_.ki += optimizer_data.ki_start / (2 ^ act_step);
		my_controller.set_ki(actual_pid_.ki);

		actual_pid_.error = this->watch_error(my_controller);

		if (actual_pid_.error < optimal_pid_.error)
		{
			optimal_pid_.ki = actual_pid_.ki;
			optimal_pid_.error = actual_pid_.error;
		}
		else
			actual_pid_.ki -= optimizer_data.ki_start / (2 ^ act_step);

		my_controller.set_ki(actual_pid_.ki);


		// ================================================
		// ====================== D =======================
		// ================================================

		actual_pid_.kd += optimizer_data.kd_start / (2 ^ act_step);
		my_controller.set_kd(actual_pid_.kd);

		actual_pid_.error = this->watch_error(my_controller);

		if (actual_pid_.error < optimal_pid_.error)
		{
			optimal_pid_.kd = actual_pid_.kd;
			optimal_pid_.error = actual_pid_.error;
		}
		else
			actual_pid_.kd -= optimizer_data.kd_start / (2 ^ act_step);

		my_controller.set_kd(actual_pid_.kd);
	}
}

// ===============================================================
// GET OPTIMUM (get stored optimum without running optimizer again)

Pid Pid_optimizer::get_optimum() const
{
	return this->optimal_pid_;
}


// ===============================================================
// WATCH ERROR (to be able to compare the affects of different P, I and D values)

double Pid_optimizer::watch_error(Controller& my_controller) const
{
	double current_error = 0;
	double max_error = 0;
	double sum_error = 0;

	static elapsed time_last_call = 0;


	// =============== TIME MANAGEMENT ================

#if _WIN32 || _WIN64										// WINDOWS
	static auto act_time = my_controller.get_time();
	auto time_passed = act_time - time_last_call;
	time_last_call = act_time;
#else														// RASPBERRY
	auto time_passed = this->get_time() - time_last_call;
	time_last_call = this->get_time();
#endif


	// =============== ERROR MANAGEMENT ================

	for (elapsed time = 0; time < watch_time; time += time_passed)
	{
		current_error = my_controller.run();

		if(current_error > max_error)
			max_error = current_error;

		sum_error += abs(current_error);
	}


	return sum_error / (max_error*watch_time);
}
