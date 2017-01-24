#include "Climber.h"
#include "../RobotMap.h"
#include "WPILib.h"
#include "PinEnums.h"
#include "Spark.h"

Climber::Climber(MotorPin climberPin) :
Subsystem("ExampleSubsystem"),
climber(climberPin)
{

}

void Climber::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void Climber::SetSpeed(double climberSpeed) {
	climber.Set(climberSpeed);
}
