#include "GearPneumatic.h"
#include "../RobotMap.h"
#include "WPILib.h"
#include "PinEnums.h"

GearPneumatic::GearPneumatic(SolenoidPin pin1, SolenoidPin pin2) :
Subsystem("ExampleSubsystem"),
gearArms(pin1, pin2)
{

}

void GearPneumatic::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void GearPneumatic::GearExtend() {
	gearArms.Set(DoubleSolenoid::Value::kForward);
}

void GearPneumatic::GearRetract() {
	gearArms.Set(DoubleSolenoid::Value::kReverse);
}

void GearPneumatic::Stop() {
	gearArms.Set(DoubleSolenoid::Value::kOff);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
