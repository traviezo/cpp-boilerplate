#include <iostream>
#include <lib.hpp>
#include <PidController.hpp>

int main()
{
    double newVel = 0.0;
    PidController pidCtrl(100.0,100.0,100.0,100.0);
    newVel = pidCtrl.computePID(30.0,22.0);
    std::cout<<"New velocity is : "<<newVel<<std::endl;
    dummy();
    return 0;
}
