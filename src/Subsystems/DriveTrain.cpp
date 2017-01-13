#include "DriveTrain.h"
#include "../RobotMap.h"

DriveTrain::DriveTrain(MotorPin left, MotorPin right) :
	Subsystem("DriveTrain"),
	leftMotors(left),
	rightMotors(right),
	InlineDrive(leftMotors, rightMotors)
{
	leftMotors.SetInverted(false);
	rightMotors.SetInverted(false);
}

void DriveTrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
