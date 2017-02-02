#include "BoilerVisionCalculation.h"
#include "../RobotMap.h"

BoilerVisionCalculation::BoilerVisionCalculation() : Subsystem("BoilerVisionCalculation"), goalX(0) {
	networkTable = NetworkTable::GetTable("othervision/targets");
}

BoilerVisionCalculation::~BoilerVisionCalculation()
{
	networkTable = NULL;
}

void BoilerVisionCalculation::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

float BoilerVisionCalculation::GoalAngle() {
	const int desiredPosition = 160;
	xVals = networkTable->GetNumberArray("centerX", llvm::ArrayRef<double>());
	if (xVals.size() == 2)
	{
		goalX = ((float)xVals[0] + (float)xVals[1])/2.0;
	}
	else
	{
		goalX = desiredPosition;
	}
	return goalX - desiredPosition;
}

float BoilerVisionCalculation::GoalDistance() {
	distVals = networkTable->GetNumberArray("centerY", llvm::ArrayRef<double>());
	if (!distVals.empty())
	{
		goalHeight = ((float)distVals[0] + (float)distVals[1])/2.0;
	}
	else
	{
		goalHeight = 0;
	}

	return goalHeight;
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
