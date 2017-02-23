#include <PidController.hpp>

PidController::PidController(double kp,double ki,double kd,double samplingTime){
	Kp = kp;
	Ki = ki;
	Kd = kd;
	dt = samplingTime;
}

double PidController::computePID(double targetSetPoint, double actualVelocity){
	
	double newVelocity = 15.00;
	//Comment out newVelocity initialized value	
	// Assume previousError  = 0
	// Enter code to compute new Velocity

	return newVelocity;
}
