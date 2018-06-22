
/********************************
#   Balancing Ball              #
#   ControllerTest.cpp                #
#                               #
#   Authors:                    #
#       KEMPERLE Andreas        #
#       NEUHOLD  Michaela       #
#       SOUKUP   Jakob          #
#       WINKLER  Andreas        #
#                               #
#   created: 2018/06/06         #
#   Version: 2018/06/06 - V1.0  #
********************************/


// ===============================================================
// INCLUDES

#include "stdafx.h"
#include "CppUnitTest.h"
#include "../BalanceLib/Controller.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestController
{
	TEST_CLASS(Controller_test)
	{
	public:

		TEST_METHOD(Test_control_clockwise) //testing function control()
		{
			Ball ball;
			Beam beam;
			Pid pid_data;
			Controller c(ball, beam, pid_data);

			// controller has to turn beam clockwise (angle > 0)
			c.ball_.set_position(-0.1);
			c.ball_.set_velocity(0);
			double desired_angle = c.control(c.ball_.get_position());
			Assert::IsTrue(desired_angle > static_cast<double>(0));
		}

		TEST_METHOD(Test_control_counterclockwise) //testing function control()
		{
			Ball ball;
			Beam beam;
			Pid pid_data;
			Controller c(ball, beam, pid_data);

			// controller has to turn beam counterclockwise (angle < 0)
			c.ball_.set_position(0.2);
			c.ball_.set_velocity(0);
			double desired_angle = c.control(c.ball_.get_position());
			Assert::IsTrue(desired_angle < static_cast<double>(0));
		}


		TEST_METHOD(Test_run__ball_left_side) //testing function run()
		{
			Ball ball;
			Beam beam;
			Pid pid_data;
			Controller controller(ball, beam, pid_data);

			
			// beam tilted to the right
			controller.ball_.set_position(-0.5);
			controller.ball_.set_velocity(0);
			controller.run();
			Assert::IsTrue(controller.ball_.get_velocity() > 0);
		}


		TEST_METHOD(Test_run__ball_right_side) //testing function run()
		{
			Ball ball;
			Beam beam;
			Pid pid_data;
			Controller controller(ball, beam, pid_data);

			// beam tilted to the left
			controller.ball_.set_position(0.5);
			controller.ball_.set_velocity(0);
			controller.run();
			Assert::IsTrue(controller.ball_.get_velocity() < 0);
		}
	};
}
