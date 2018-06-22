
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
#include "Controller.h"


// #################################### SECTION BREAK ####################################


// ===============================================================
// GET OPTIMUM (get stored optimum without running optimizer again)
// ===============================================================

Pid Pid_optimizer::get_optimum(Optimizer& optimizer_data)
{
	// ============ RUN OPTIMIZER ==============
	this->run(optimizer_data);
	// =========================================

	return this->optimal_pid_;
}


// #######################################################################################
// ################################## PRIVATE FUNCTIONS ##################################
// #######################################################################################


// ===============================================================
// RUN OPTIMIZER
// ===============================================================

void Pid_optimizer::run(Optimizer& optimizer_data)
{
	Ball ball;
	Beam beam;
	Controller controller{ ball, beam, optimizer_data.kp_start, optimizer_data.ki_start, optimizer_data.kd_start };


	// ======= INITIALIZE P, I, D =========
	actual_pid_.kp = optimizer_data.kp_start;
	actual_pid_.ki = optimizer_data.ki_start;
	actual_pid_.kd = optimizer_data.kd_start;
	// ====================================


	for (steps act_step = 0; act_step < optimizer_data.k_steps; act_step++)
	{
		// ========= TRY DIFFERENT P, I, D =========
		this->try_kp(controller, this->actual_pid_, optimizer_data, act_step);
		this->try_ki(controller, this->actual_pid_, optimizer_data, act_step);
		this->try_kd(controller, this->actual_pid_, optimizer_data, act_step);
		// =========================================


		// ========= SAVE OPTIMAL P, I, D ==========
		this->optimal_pid_.kp = this->actual_pid_.kp;
		this->optimal_pid_.ki = this->actual_pid_.ki;
		this->optimal_pid_.kd = this->actual_pid_.kd;
		this->optimal_pid_.error = this->actual_pid_.kd;
		// =========================================
	}
}


// #################################### SECTION BREAK ####################################


// ===============================================================
// TRY ANOTHER KP
// ===============================================================

void Pid_optimizer::try_kp(Controller& controller, Pid & actual_pid, Optimizer & optimizer_data, steps act_step)
{
	actual_pid_.kp += optimizer_data.kp_start / (2 ^ act_step);
	controller.set_kp(actual_pid_.kp);


	// ============ SIMILATION ============
	actual_pid_.error = this->watch_error(controller);
	// ====================================


	// =========== ERROR MANAGEMENT ============
	if (actual_pid_.error < optimal_pid_.error)
	{
		optimal_pid_.kp = actual_pid_.kp;
		optimal_pid_.error = actual_pid_.error;
	}
	else
		actual_pid_.kp -= optimizer_data.kp_start / (2 ^ act_step);
	// =========================================


	controller.set_kp(actual_pid_.kp);
}


// ===============================================================
// TRY ANOTHER KI
// ===============================================================

void Pid_optimizer::try_ki(Controller& controller, Pid & actual_pid, Optimizer & optimizer_data, steps act_step)
{
	actual_pid_.ki += optimizer_data.ki_start / (2 ^ act_step);
	controller.set_ki(actual_pid_.ki);


	// ============ SIMILATION ============
	actual_pid_.error = this->watch_error(controller);
	// ====================================


	// =========== ERROR MANAGEMENT ============
	if (actual_pid_.error < optimal_pid_.error)
	{
		optimal_pid_.ki = actual_pid_.ki;
		optimal_pid_.error = actual_pid_.error;
	}
	else
		actual_pid_.ki -= optimizer_data.ki_start / (2 ^ act_step);
	// =========================================


	controller.set_ki(actual_pid_.ki);
}


// ===============================================================
// TRY ANOTHER KD
// ===============================================================

void Pid_optimizer::try_kd(Controller & controller, Pid & actual_pid, Optimizer & optimizer_data, steps act_step)
{
	actual_pid_.kd += optimizer_data.kd_start / (2 ^ act_step);
	controller.set_kd(actual_pid_.kd);


	// ============ SIMILATION ============
	actual_pid_.error = this->watch_error(controller);
	// ====================================


	// =========== ERROR MANAGEMENT ============
	if (actual_pid_.error < optimal_pid_.error)
	{
		optimal_pid_.kd = actual_pid_.kd;
		optimal_pid_.error = actual_pid_.error;
	}
	else
		actual_pid_.kd -= optimizer_data.kd_start / (2 ^ act_step);
	// =========================================


	controller.set_kd(actual_pid_.kd);
}


// #################################### SECTION BREAK ####################################


// ===============================================================
// WATCH ERROR (to be able to compare the affects of differen P, I and D values)
// ===============================================================

double Pid_optimizer::watch_error(Controller& controller) const
{
	double current_error = 0;
	double max_error = 0;
	double sum_error = 0;

	elapsed last_call = controller.get_time();
	elapsed time_passed = 0;


	for (elapsed time = 0; time < watch_time; time += time_passed)
	{
		// ============ TIME MANAGEMENT ============
		time_passed = controller.get_time() - last_call;
		last_call += time_passed;
		// =========================================



		// =========== ERROR MANAGEMENT ============
		current_error = controller.run();

		if (current_error > max_error)
			max_error = current_error;

		sum_error += abs(current_error);
		// =========================================
	}

	return sum_error / (max_error*watch_time);
}