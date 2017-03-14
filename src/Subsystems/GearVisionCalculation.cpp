#include "GearVisionCalculation.h"
#include "../RobotMap.h"

GearVisionCalculation::GearVisionCalculation() : Subsystem("GearVisionCalculation"), goalX(0) {
	networkTable = NetworkTable::GetTable("vision/targets_Rear");
}

GearVisionCalculation::~GearVisionCalculation()
{
	networkTable = NULL;
}

void GearVisionCalculation::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

float GearVisionCalculation::GoalAngle() {
	//const int desiredPosition = 72.25;
	const int desiredPosition = 160;
	xVals = networkTable->GetNumberArray("centerX", llvm::ArrayRef<double>());
	/*if (xVals.size() == 2)
	{
		goalX = ((float)xVals[0] + (float)xVals[1])/2.0;
	}
	else
	{
		goalX = desiredPosition;
	}*/
	goalX = ((float)xVals[0]);
	return goalX - desiredPosition;
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
