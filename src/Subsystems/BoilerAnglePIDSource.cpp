/*
 * BoilerAnglePIDSource.cpp
*/
#include <Subsystems/BoilerAnglePIDSource.h>
#include "Subsystems/BoilerVisionCalculation.h"

BoilerAnglePIDSource::BoilerAnglePIDSource(BoilerVisionCalculation* bC)
:boilerVisionCalculation(bC)
{
	// TODO Auto-generated constructor stub

}

BoilerAnglePIDSource::~BoilerAnglePIDSource() {
	// TODO Auto-generated destructor stub
}

double BoilerAnglePIDSource::PIDGet()
{
	double result = -boilerVisionCalculation->GoalAngle()/320.0;
	SmartDashboard::PutNumber("BoilerAnglePIDGet", result);
	return result;
}
