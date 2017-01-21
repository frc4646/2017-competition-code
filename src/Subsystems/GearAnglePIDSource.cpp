/*
 * GearAnglePIDSource.cpp
*/
#include <Subsystems/GearAnglePIDSource.h>
#include "Subsystems/GearVisionCalculation.h"

GearAnglePIDSource::GearAnglePIDSource(GearVisionCalculation* gC)
:gearVisionCalculation(gC)
{
	// TODO Auto-generated constructor stub

}

GearAnglePIDSource::~GearAnglePIDSource() {
	// TODO Auto-generated destructor stub
}

double GearAnglePIDSource::PIDGet()
{
	double result = -gearVisionCalculation->GoalAngle()/320.0;
	SmartDashboard::PutNumber("PIDGet", result);
	return result;
}
