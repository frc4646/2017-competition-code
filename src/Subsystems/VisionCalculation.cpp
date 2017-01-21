#include "VisionCalculation.h"
#include "../RobotMap.h"

VisionCalculation::VisionCalculation() : Subsystem("VisionCalculation")
{
	networkTable = NetworkTable::GetTable("vision/targets");
}

VisionCalculation::~VisionCalculation()
{
	networkTable = NULL;
}

void VisionCalculation::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
