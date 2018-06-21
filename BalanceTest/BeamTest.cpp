
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
		}
	};


	TEST_CLASS(test_angle)
	{
	public:

		TEST_METHOD(test_positive_angle)
		{
			Beam test_beam;

			test_beam.set_angle(17.9, 1000);
			Assert::AreEqual(static_cast<double>(17.9), test_beam.get_angle());

			test_beam.set_angle(40, 1000);
			Assert::AreEqual(static_cast<double>(22.5), test_beam.get_angle());
		}

		TEST_METHOD(test_negative_angle)
		{
			Beam test_beam;

			test_beam.set_angle(-11.2, 1000);
			Assert::AreEqual(static_cast<double>(-11.2), test_beam.get_angle());

			test_beam.set_angle(-40, 1000);
			Assert::AreEqual(static_cast<double>(-22.5), test_beam.get_angle());
		}
	};


	TEST_CLASS(test_ang_velocity)
	{
	public:

		TEST_METHOD(test_negative_velocity)
		{
			Beam test_beam;

			test_beam.set_angle(-50.8, 100);
			Assert::AreEqual(static_cast<double>(-4.5), test_beam.get_angle());	// maximum value: 45°/s
		}

		TEST_METHOD(test_positive_velocity)
		{
			Beam test_beam;

			test_beam.set_angle(61.9, 100);
			Assert::AreEqual(static_cast<double>(4.5), test_beam.get_angle());	// maximum value: 45°/s
		}
	};

}