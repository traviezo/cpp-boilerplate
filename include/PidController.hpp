/**
  * @file PidController.h
  * @version 1.0
  * @date 02/20/17
  * @author Christian Ramos
  * @title Class PidController
  * @brief PID controller algorithm that calculates new velocity. 
  */

#ifndef PID_CONTROLLER_H
#define PID_CONTROLLER_H

#include <iostream>

class PidController{

	public:
		/**
		  * @brief Constructor that initiates all class data members
		  * @param kp Proportional Constant
		  * @param ki Integral Constant
		  * @param kd Derivative Constant
		  * @param samplingTime Time between measurements
		  * @param max Computed velocity upper limit 
		  * @param min Computed velocity lower limit
		  * @return newVelocity New calculated velocity   
		  */
		PidController(double kp,double ki,double kd,double samplingTime);

		/**
		  * @brief Object Destructor.
		  */
		~PidController(){};

		/**
		  * @brief Given a target set point and actual velocity, it computes a new velocity
		  * @param targetSetPoint Represents desired velocity
		  * @param actualVelocity Represents the current velocity
		  * @return newVelocity New calculated velocity   
		  */		
		double computePID(double targetSetpoint, double actualVelocity);
	private:
		double Kp;
		double Ki;
		double Kd;
		double dt;
		double previousError;
		double integral;
};

#endif	// PID_CONTROLLER_H
