#include <gtest/gtest.h>
#include <systemc.h>
#include <string>
#include <vector>

#define NB 8
#define NI 1

using namespace std;

#include "counter3.h"

// Test fixture, modify SetUp() or TearDown()
class Counter3Basics : public testing::Test{
    protected:
        void SetUp() override {
            dut = new counter3("");
        }
        void TearDown() override {
            delete dut;
        }

        counter3 *dut;
};

TEST_F(Counter3Basics, IncrementOneOnlyIncrementsByOne){
    int x = 0;
    x = dut->increment_one(x);
    EXPECT_EQ(1, x);

    x = 5;
    x = dut->increment_one(x);
    EXPECT_EQ(5, x);
}

TEST_F(Counter3Basics, IncrementOneOverflowsAfter7){
    int x = 0;
    for(int i = 0; i < 7; i++){
        x = dut->increment_one(x);
        EXPECT_EQ(1 + i, x);
    }
    x = dut->increment_one(x);
    EXPECT_EQ(0, x);
}

// Main routine
int sc_main(int argc, char** argv){
    // sc_start();
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}