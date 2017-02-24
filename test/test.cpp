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

TEST(PidConstructor, InvalidNegativeGainInputs)
{
    EXPECT_THROW(PidController(-22.0,-0.1,-5.7,1.0), std::domain_error);
}

TEST(PidConstructor, InvalidNegativeTimeArgument)
{
    EXPECT_THROW(PidController(18.0,7.3,1.5,-1.0), std::domain_error);
}

TEST(PidConstructor, InvalidZeroTimeArgument)
{
    EXPECT_THROW(PidController(34.0,3.6,2.8,0), std::runtime_error);
}
