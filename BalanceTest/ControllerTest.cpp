
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
#include <chrono>
#include <thread>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestController
{
	TEST_CLASS(Controller_test)
	{
	public:
		/*TEST_METHOD(Test_construction)
		{
			Ball ball;
			Beam beam;
			Controller c(ball, beam, 1, 2, 3);
			Assert::AreEqual(ball, c.ball_);
			Assert::AreEqual(beam, c.beam_);
		}*/

		TEST_METHOD(Test_control_calc) //testing function control() by calculation, assuming that elapsed time is 1000 ms
		{
			Ball ball;
			Beam beam(2, 0, 0);
			Controller c(ball, beam, 1, 2, 3);

			c.ball_.set_position(-1);
			Assert::AreEqual(21.3, c.control(c.ball_.get_position()));
		}

		TEST_METHOD(Test_control) //testing function control()
		{
			Ball ball;
			Beam beam(2,0,0);
			Controller c(ball, beam, 1, 2, 3);

			c.ball_.set_position(-1);
			Assert::IsTrue(c.control(c.ball_.get_position()) > 0);
		}

		TEST_METHOD(Test_update) //testing function update()
		{
			Ball ball;
			Beam beam(2, 0, 0);
			Controller c(ball, beam, 1, 2, 3);
			
			//beam tilted to the right
			c.update(20);
			Assert::IsTrue(c.ball_.get_velocity() > 0);
			
			//beam tilted to the left
			c.ball_.set_velocity(0);
			c.ball_.set_position(0);
			c.update(-20);
			Assert::IsTrue(c.ball_.get_velocity() < 0);
		}

		TEST_METHOD(get_time) //testing timing function (happens to fail, but result is correct, if value is 10 or 11)
		{
			Ball ball;
			Beam beam(2, 0, 0);
			Controller c(ball, beam, 1, 2, 3);
			
			elapsed demo = 10;
			elapsed first = c.clock_.get_time();
			using namespace std::this_thread; // sleep_for
			using namespace std::chrono; // milliseconds
			sleep_for(milliseconds(10));
			Assert::AreEqual(demo, c.clock_.get_time() - first);
		}
	};
}
