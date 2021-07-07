#include "PID.h"
#include <iostream>
/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  Kp=Kp_;
  Ki=Ki_;
  Kd=Kd_;
  prev_error=0;
  d_error=0;
  i_error=0;
  prev_i=0;
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
  
  p_error = -1*Kp*cte;
  i_error =prev_i;
  d_error= (d_error*0.0016)+((cte  -prev_error)*-1*Kd*0.9984);  
  prev_error=cte;
  prev_i+=-1*Ki*i_error*cte;
  
}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  double totalerror=p_error+i_error+d_error;
  
  return totalerror;  // TODO: Add your total error calc here!
}