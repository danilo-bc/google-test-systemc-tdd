#include <gtest/gtest.h>
#include <systemc.h>
#include <string>
#include <vector>

#define NB 8
#define NI 1

using namespace std;

#include "counter3.h"

TEST(Counter3Basics, IncrementOneOnlyIncrementsByOne){
    counter3 dut("MYCOUNTER3");
    int x = 0;
    x = dut.increment_one(x);
    EXPECT_EQ(1, x);

    x = 5;
    x = dut.increment_one(x);
    EXPECT_EQ(5, x);
}

TEST(Counter3Basics, IncrementOneOverflowsAfter7){
    counter3 dut("MYCOUNTER3_3");
    int x = 0;
    for(int i = 0; i < 7; i++){
        x = dut.increment_one(x);
        EXPECT_EQ(1 + i, x);
    }
    x = dut.increment_one(x);
    EXPECT_EQ(0, x);
}

// Main routine
int sc_main(int argc, char** argv){
    // sc_start();
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}