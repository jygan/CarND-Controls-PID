#include "PID.h"

//using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	p_error = 0.0;
	i_error = 0.0;
	d_error = 0.0;
	//Assign initial variables
	PID::Kp = Kp;
	PID::Ki = Ki;
	PID::Kd = Kd;
	
	//Parameters
	step = 1;
	
	
}

void PID::UpdateError(double cte) {
	//Calculate Errors
	if ( step == 1 ) {
		p_error = cte;
		step = 2;
	}
	d_error = cte - p_error;
	p_error = cte;
	i_error += cte;
	
}

double PID::TotalError() {
	return -Kp * p_error - Kd * d_error - Ki * i_error;
}

