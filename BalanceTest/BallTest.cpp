
/********************************
#   Balancing Ball              #
#   BallTest.cpp                #
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
#include "../BalanceLib/Ball.h"


// ===============================================================
// NAMESPACES

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


// #################################### SECTION BREAK ####################################


// ===============================================================
// NAMESPACE FOR ALL BALL TESTS

namespace ball_test
{		
	TEST_CLASS(test_default_constructor)
	{
	public:
		
		TEST_METHOD(test_default_constructor1)
		{
			Ball test_ball;

			Assert::AreEqual(static_cast<double>(0), test_ball.get_position());
			Assert::AreEqual(static_cast<double>(0), test_ball.get_velocity());
		}
	};


	TEST_CLASS(test_position)
	{
	public:

		TEST_METHOD(test_positive_position)
		{
			Ball test_ball;

			test_ball.set_position(1.2);
			Assert::AreEqual(static_cast<double>(1.2), test_ball.get_position());
		}

		TEST_METHOD(test_negative_position)
		{
			Ball test_ball;

			test_ball.set_position(-1.8);
			Assert::AreEqual(static_cast<double>(-1.8), test_ball.get_position());
		}
	};


	TEST_CLASS(test_velocity)
	{
	public:	
		TEST_METHOD(test_negative_velocity)
		{
			Ball test_ball;

			test_ball.set_velocity(-0.7);
			Assert::AreEqual(static_cast<double>(-0.7), test_ball.get_velocity());
		}

		TEST_METHOD(test_positive_velocity)
		{
			Ball test_ball;

			test_ball.set_velocity(2.9);
			Assert::AreEqual(static_cast<double>(2.9), test_ball.get_velocity());
		}
	};


	TEST_CLASS(test_push)
	{
	public:
		TEST_METHOD(test_push_left)
		{
			Ball test_ball;

			test_ball.push(Push::left, 0.7);
			Assert::AreEqual(static_cast<double>(-0.7), test_ball.get_velocity());

			test_ball.push(Push::left, 0.4);
			Assert::AreEqual(static_cast<double>(-1.1), test_ball.get_velocity());
		}

		TEST_METHOD(test_push_right)
		{
			Ball test_ball;

			test_ball.push(Push::right, 0.9);
			Assert::AreEqual(static_cast<double>(0.9), test_ball.get_velocity());
			
			test_ball.push(Push::right, 0.3);
			Assert::AreEqual(static_cast<double>(1.2), test_ball.get_velocity());
		}

		TEST_METHOD(test_push_not_defined_direction)
		{
			Ball test_ball;

			Assert::ExpectException<std::logic_error>([](){Ball test_ball; test_ball.push(static_cast<Push>(3), 0.5);});
		}
	};


	TEST_CLASS(test_velocity_and_push)
	{
	public:
		TEST_METHOD(test_push_against_velocity)
		{
			Ball test_ball;

			test_ball.set_velocity(0.2);
			test_ball.push(Push::left, 0.5);
			Assert::AreEqual(static_cast<double>(-0.3), test_ball.get_velocity());

			test_ball.set_velocity(-0.3);
			test_ball.push(Push::right, 0.5);
			Assert::AreEqual(static_cast<double>(0.2), test_ball.get_velocity());
		}

		TEST_METHOD(test_push_with_velocity)
		{
			Ball test_ball;

			test_ball.set_velocity(-0.3);
			test_ball.push(Push::left, 0.5);
			Assert::AreEqual(static_cast<double>(-0.8), test_ball.get_velocity());

			test_ball.set_velocity(0.2);
			test_ball.push(Push::right, 0.5);
			Assert::AreEqual(static_cast<double>(0.7), test_ball.get_velocity());
		}
	};
}