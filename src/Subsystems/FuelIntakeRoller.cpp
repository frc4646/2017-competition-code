#include "FuelIntakeRoller.h"
#include "../RobotMap.h"
#include "WPILib.h"
#include "Spark.h"
#include "PinEnums.h"

FuelIntakeRoller::FuelIntakeRoller(MotorPin rollerPin) :
Subsystem("ExampleSubsystem"),
roller(rollerPin)
{
	roller.SetInverted(true);
}

void FuelIntakeRoller::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void FuelIntakeRoller::SetSpeed(double speed) {
	roller.Set(speed);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
