// Copyright 2019 fayxx092
/* STUDENTS: YOU MUST ADD YOUR PASSENGER UNIT TESTS TO THIS FILE. FORMAT YOUR
 * TESTS TO FIT THE SPECIFICATIONS GIVEN BY THE TESTS PROVIDED IN THIS FILE.
 *
 * Please note, the assessment tests for grading, will use the same include
 * files, class names, and function names for accessing students' code that you
 * find in this file.  So students, if you write your code so that it passes
 * these feedback tests, you can be assured that the auto-grader will at least
 * be able to properly link with your code.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <gtest/gtest.h>
#include "../src/passenger.h"

/******************************************************
* TEST FEATURE SetUp
*******************************************************/
class PassengerTests : public ::testing::Test {
 protected:
    Passenger* passenger;
    Passenger* waitPassenger;

  virtual void SetUp() {
    passenger = new Passenger();
    waitPassenger = new Passenger();
		passenger3 = new Passenger();
    }

  virtual void TearDown() {
    delete passenger;
    delete waitPassenger;
		delete passenger3;
    }
};


/*******************************************************************************
 * Test Cases
 ******************************************************************************/

TEST_F(PassengerTests, Constructor) {
    EXPECT_EQ(passenger->IsOnBus(), false);
    passenger->GetOnBus();
    EXPECT_EQ(passenger->IsOnBus(), true);
}


TEST_F(PassengerTests, stopIdTest) {
    EXPECT_EQ(passenger->GetDestination(), -1);
}

TEST_F(PassengerTests, updateTest) {
    waitPassenger.Update();
    waitPassenger.Update();
    waitPassenger.GetOnBus();
    waitPassenger.Update();
    EXPECT_EQ(waitPassenger.GetTotalWait(), 3);
}

TEST_F(PassengerTests, TotalWaitTest) {
	passenger3.Update();
	passenger3.Update();
	passenger3.Update();
	passenger3.Update();
	passenger3.GetOnBus();
	passenger3.Update();
	EXPECT_EQ(passenger3.GetTotalWait(), 5);
}
