#include "UltrasonicSensor.h"
#include "../RobotMap.h"
#include "WPILib.h"
#include "PinEnums.h"

UltrasonicSensor::UltrasonicSensor(AnalogPin UPin) :
Subsystem("ExampleSubsystem"),
USensor(new AnalogInput(UPin))
{

}

void UltrasonicSensor::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

double UltrasonicSensor::GetVoltage() {
	return USensor->GetVoltage();
}

double UltrasonicSensor::GetDistance() {
	return USensor->GetVoltage()/.012;
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
