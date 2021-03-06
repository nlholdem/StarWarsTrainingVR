
#pragma once

#include "CoreMinimal.h"

/**
 *
 */
class PIDController
{
public:
	PIDController(double _min, double _max, double _Kp, double _Kd, double _Ki);
	~PIDController();
	double update(double setpoint, double state, double dt);

private:
	double max;
	double min;
	double Kp;
	double Kd;
	double Ki;
	double error_old;
	double integral;
};
