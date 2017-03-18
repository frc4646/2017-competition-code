#include "Indexer.h"
#include "../RobotMap.h"

Indexer::Indexer(MotorPin indexerPin) : Subsystem("ExampleSubsystem"),
index(indexerPin)
{
	index.SetInverted(false);
}

void Indexer::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void Indexer::SetSpeed(double power) {
	index.Set(power);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
