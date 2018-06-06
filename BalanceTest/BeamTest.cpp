
/********************************
#   Balancing Ball              #
#   BeamTest.cpp                #
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
#include "../BalanceLib/Beam.h"


// ===============================================================
// NAMESPACES

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


// #################################### SECTION BREAK ####################################


// ===============================================================
// NAMESPACE FOR ALL BALL TESTS

namespace beam_test
{		
	TEST_CLASS(test_default_constructor)
	{
	public:
		
		TEST_METHOD(test_default_constructor1)
		{
			Beam test_beam;

			Assert::AreEqual(static_cast<double>(2), test_beam.get_lenght());
			Assert::AreEqual(static_cast<double>(0), test_beam.get_angle());
			Assert::AreEqual(static_cast<double>(0), test_beam.get_ang_velocity());
		}
	};


	TEST_CLASS(test_angle)
	{
	public:

		TEST_METHOD(test_positive_angle)
		{
			Beam test_beam;

			test_beam.set_angle(17.3);
			Assert::AreEqual(static_cast<double>(17.3), test_beam.get_angle());
		}

		TEST_METHOD(test_negative_angle)
		{
			Beam test_beam;

			test_beam.set_angle(-3.8);
			Assert::AreEqual(static_cast<double>(-3.8), test_beam.get_angle());
		}
	};


	TEST_CLASS(test_ang_velocity)
	{
	public:

		TEST_METHOD(test_negative_velocity)
		{
			Beam test_beam;

			test_beam.set_ang_velocity(-0.7);
			Assert::AreEqual(static_cast<double>(-0.7), test_beam.get_ang_velocity());
		}

		TEST_METHOD(test_positive_velocity)
		{
			Beam test_beam;

			test_beam.set_ang_velocity(0.9);
			Assert::AreEqual(static_cast<double>(0.9), test_beam.get_ang_velocity());
		}
	};

}