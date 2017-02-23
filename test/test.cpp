#include <gtest/gtest.h>
#include <PidController.hpp>

TEST(PidController, computePID1)
{
    PidController pidCtrl(1.0,5,0.1,0.1);
    EXPECT_EQ(25,pidCtrl.computePID(30.0,20.0));
}

TEST(PidController, computePID2)
{
    PidController pidCtrl(0.5,2.0,0.1,0.1);
    EXPECT_EQ(25.5,pidCtrl.computePID(25.0,10.0));
}
