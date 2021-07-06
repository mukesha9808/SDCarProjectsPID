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
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
  p_error = cte;
  i_error +=cte;
  d_error= cte  -prev_error;  
  prev_error=cte;
}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  double totalerror=(-1*Kp*p_error)+(-1*Ki*i_error)+(-1*Kd*d_error);
  
  return totalerror;  // TODO: Add your total error calc here!
}