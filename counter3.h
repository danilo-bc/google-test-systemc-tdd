#include <systemc.h>

#ifndef COUNTER3_H
#define COUNTER3_H

SC_MODULE (counter3) {
    private:
    int current_count;

    public:
    sc_in<bool> reset_n;
    sc_in<bool> clk;

    int increment_one(int );
    void counter3_proc();

    SC_CTOR (counter3)
    {
        SC_CTHREAD(counter3_proc, clk.pos());
        async_reset_signal_is(reset_n, false);
    }
}; //reminder that C++ classes require ";"

#endif