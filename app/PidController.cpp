#include <PidController.hpp>

PidController::PidController(double kp,double ki,double kd,double samplingTime){
	Kp = kp;
	Ki = ki;
	Kd = kd;
	dt = samplingTime;
}

double PidController::computePID(double targetSetpoint, double actualVelocity){
	double newVelocity = 15.00;

	// Enter code to compute new Velocity

	return newVelocity;
}
