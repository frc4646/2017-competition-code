/*
 * BoilerDistancePIDSource.cpp
*/
#include <Subsystems/BoilerDistancePIDSource.h>
#include "Subsystems/BoilerVisionCalculation.h"

BoilerDistancePIDSource::BoilerDistancePIDSource(BoilerVisionCalculation* bC)
:boilerVisionCalculation(bC)
{
	// TODO Auto-generated constructor stub

}

BoilerDistancePIDSource::~BoilerDistancePIDSource() {
	// TODO Auto-generated destructor stub
}

double BoilerDistancePIDSource::PIDGet()
{
	double result = -boilerVisionCalculation->GoalDistance()/160;
	SmartDashboard::PutNumber("BoilerDistancePIDGet", result);
	return result;
}
