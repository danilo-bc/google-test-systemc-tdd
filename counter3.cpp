#include <systemc.h>
#include "counter3.h"

int counter3::increment_one(int input_n){
    input_n += 1;

    if(input_n > 7 || input_n < 0){
        input_n = 0;
    }

    return input_n;
}

void counter3::counter3_proc(){
        if(!reset_n){
            current_count = 42;
        }
        while(true){
            current_count = increment_one(current_count);
            wait();
        }
        cout<<"Proccess"<<endl;
}