#include "PressureSensor.h"
#include "../RobotMap.h"

PressureSensor::PressureSensor(AnalogPin PPin) :
Subsystem("ExampleSubsystem"),
PSensor(new AnalogInput(PPin))
{
	networkTable = NetworkTable::GetTable("PRESSURE");
}

void PressureSensor::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

double PressureSensor::GetVoltage() {
	return PSensor->GetVoltage();
}

double PressureSensor::GetPressure() {
	networkTable->PutNumber("Pressure",((PSensor->GetVoltage()*50)-25));
	return ((PSensor->GetVoltage()*50)-25);
}

void PressureSensor::SendSD() {
	SmartDashboard::PutNumber("Pressure", GetPressure());
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
