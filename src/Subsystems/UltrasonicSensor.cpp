#include "UltrasonicSensor.h"
#include "../RobotMap.h"
#include "WPILib.h"
#include "PinEnums.h"
#include "Commands/SendUltrasonic.h"

UltrasonicSensor::UltrasonicSensor(AnalogPin UPin) :
Subsystem("ExampleSubsystem"),
USensor(new AnalogInput(UPin))
{
	networkTable = NetworkTable::GetTable("ultrasonic");
}

void UltrasonicSensor::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

double UltrasonicSensor::GetVoltage() {
	return USensor->GetVoltage();
}

double UltrasonicSensor::GetDistance() {
	networkTable->PutNumber("Ultrasonic",(USensor->GetVoltage()/.012));
	return USensor->GetVoltage()/.012;

}

void UltrasonicSensor::SendSD() {
	SmartDashboard::PutNumber("UltrasonicDistance", GetDistance());
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
