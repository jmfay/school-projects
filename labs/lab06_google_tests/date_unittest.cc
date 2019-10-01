#include "gtest/gtest.h"

#include <iostream>
#include <math.h>
#include <ctime>

#include "date.h"


class DateTest : public ::testing::Test {
 public:
  void SetUp( ) {
    // code here will execute just before the test ensues
	first_day = Date(2018, 9, 4);
	last_day = Date(2018, 12, 11);
  }
 protected:
  Date first_day;          // first day of classes
  Date last_day;           // last day of classes
};

TEST_F(DateTest, PrintDateTests) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween

  std::string expected_out_1 = "1999-12-31\n";
  std::string expected_out_2 = "1776-07-04\n";
  std::string expected_out_3 = "2018-10-31\n";

  testing::internal::CaptureStdout();
  y2k.PrintDate(true);
  std::string output1 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout(); // You must do this EVERY TIME, or else it will segfault
  ind_day.PrintDate(true);
  std::string output2 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  best_holiday.PrintDate(true);
  std::string output3 = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
}

TEST_F(DateTest, PrintDateTestsWithoutNewline) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween

  std::string expected_out_1 = "1999-12-31";
  std::string expected_out_2 = "1776-07-04";
  std::string expected_out_3 = "2018-10-31";

  testing::internal::CaptureStdout();
  y2k.PrintDate(false);
  std::string output1 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  ind_day.PrintDate(false);
  std::string output2 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  best_holiday.PrintDate(false);
  std::string output3 = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
}

/**
  *
  * Note, this is the only provided test case which actually uses our test fixture
  *
  * However, it is illegal to mix TEST() and TEST_F() in the same test case (file).
  *
  */

TEST_F(DateTest, DaysBetweenTests) {
  EXPECT_EQ(first_day.GetUsDate(), "09-04-2018") << "First day of class not setup properly";
  EXPECT_EQ(last_day.GetUsDate(), "12-11-2018") << "Last day of class not setup properly";
  EXPECT_EQ(first_day.DaysBetween(last_day), 98) << "Days between is not calculated properly";
}

//EPOCH Test

TEST_F(DateTest, EpochConstructorTests){
  Date christmas(1577232000);     //christmas day 2019
  Date origin(0);                 //beginning of UTC
  Date negative_input(-1);         //negative input
  EXPECT_EQ(christmas.GetUsDate(), "12-25-2019") << "Standard epoch construction not working";
  EXPECT_EQ(origin.GetUsDate(), "01-01-1970") << "UTC origin not working properly";
  EXPECT_EQ(negative_input.GetUsDate(), "12-31-1969") << "Negative epoch input not handled properly";
}

//FIX THIS TEST TO BE DYNAMIC TO TODAY'S DATE
TEST_F(DateTest, CurrentDayConstructorTests){
  Date today;
  EXPECT_NE(today.GetUsDate(), "08-30-2019") << "Month is zero-indexed";
  EXPECT_EQ(today.GetUsDate(), "09-30-2019") << "Today's date not calculated properly";
}

TEST_F(DateTest, GetUsDateTest){
  EXPECT_EQ(first_day.GetUsDate(), "09-04-2018") << "Format incorrect";
  EXPECT_NE(first_day.GetUsDate(), "9-4-2018") << "Leading 0s missing";
}

TEST_F(DateTest, GetDateTest){
  EXPECT_EQ(first_day.GetDate(), "2018-09-04") << "Format incorrect";

}

TEST_F(DateTest, MinusOperatorTest){
  Date originalDate(2019,9,30);
  Date newDateMinus = originalDate - 2;
  Date newDatePlus = originalDate - (-2);
  EXPECT_EQ(newDateMinus.GetUsDate(), "09-28-2019") << "Subtraction operator not set up properly";
  EXPECT_EQ(newDatePlus.GetUsDate(), "10-02-2019") << "Subtraction operator doesn't handle negatives properly";
}

TEST_F(DateTest, PlusOperatorTest){
  Date originalDate(2019,9,30);
  Date newDatePlus = originalDate + 2;
  Date newDateMinus = originalDate + (-2);
  EXPECT_EQ(newDatePlus.GetUsDate(), "10-02-2019") << "Addition operator not set up properly";
  EXPECT_EQ(newDateMinus.GetUsDate(), "09-28-2019") << "Addition operator doesn't handle negatives properly";


}

/**
  *
  * NOPE!  Can't test PRIVATE methods
  *
  */
/*
TEST(DateTest, ConvertFromDays) {
	Date convert_first_day = ConvertToDays(2458365);
	EXPECT_STREQ(convert_first_day.GetUsDate(), "09-04-2018");
}
*/
