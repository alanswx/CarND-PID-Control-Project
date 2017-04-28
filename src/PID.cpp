#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  this->Kp=Kp;
  this->Ki=Ki;
  this->Kd=Kd;

  p_error = 0;
  i_error = 0;
  d_error = 0;
  init = false;
}

void PID::UpdateError(double cte) {
  if (init==false){
     p_error = cte;
     init = true;
  }
  d_error = cte - p_error;
  p_error = cte;
  i_error += cte;
#if 0
def run(robot, tau_p, tau_d, tau_i, n=100, speed=1.0):
    x_trajectory = []
    y_trajectory = []
    prev_cte = robot.y
    int_cte = 0
    for i in range(n):
        cte = robot.y
        diff_cte = cte - prev_cte
        prev_cte = cte
        int_cte += cte
        steer = -tau_p * cte - tau_d * diff_cte - tau_i * int_cte
        robot.move(steer, speed)
        x_trajectory.append(robot.x)
        y_trajectory.append(robot.y)
    return x_trajectory, y_trajectory
#endif
}

double PID::TotalError() {
        return -Kp* p_error - Kd* d_error - Ki * i_error;
}

