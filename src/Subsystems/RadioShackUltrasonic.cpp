#include "RadioShackUltrasonic.h"
#include "../RobotMap.h"
#include <iostream>
#include <WPILib.h>
#include "Commands/SendUltrasonic.h"

using namespace frc;

RadioShackUltrasonic::RadioShackUltrasonic(int pin) : Subsystem("ExampleSubsystem")
, foo(new Counter(pin)){

	foo->SetSemiPeriodMode(true);
}

void RadioShackUltrasonic::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new SendUltrasonic());
}

double RadioShackUltrasonic::GetDistance()
{
	return foo->GetPeriod()*62598;
}


void RadioShackUltrasonic::SendSD()
{
	SmartDashboard::PutNumber("Period", GetDistance());
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
