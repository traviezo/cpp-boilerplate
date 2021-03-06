#include <PidController.hpp>

PidController::PidController(double kp,double ki,double kd,double samplingTime){
	if (isless(samplingTime,0))
		throw std::domain_error("Negative time argument is invalid");
	if (samplingTime == 0)
		throw std::runtime_error("Argument will cause a divide by zero");
	if (isless(kp,0) || isless(ki,0) || isless(kd,0))
		throw std::domain_error("Negative arguments are invalid");
	Kp = kp;
	Ki = ki;
	Kd = kd;
	dt = samplingTime;
}

/** from: https://en.wikipedia.org/wiki/PID_controller#Discrete_implementation
previous_error = 0
integral = 0
start:
  error = setpoint - measured_value
  integral = integral + error*dt
  derivative = (error - previous_error)/dt
  output = Kp*error + Ki*integral + Kd*derivative
  previous_error = error
  wait(dt)
  goto start
 */
double PidController::computePID(double targetSetPoint, double actualVelocity){
	// u(t) = Kp * e(t) + Ki * integral(0, t, e(tau), dtau) + Kd * derivative(e(t), dt)

  // e(t)
	double error = targetSetPoint - actualVelocity;

	// integral(0, t, e(tau), dtau)
	integral = integral + error*dt;

	// derivative(e(t), dt)
	double derivative = (error - previousError)/dt;

	previousError = error;

	return (Kp * error) + (Ki * integral) + (Kd * derivative);
}

