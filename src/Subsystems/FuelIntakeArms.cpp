#include "FuelIntakeArms.h"
#include "../RobotMap.h"
#include "WPILib.h"
#include "PinEnums.h"

FuelIntakeArms::FuelIntakeArms(SolenoidPin pin1, SolenoidPin pin2) :
Subsystem("ExampleSubsystem"),
arms(pin1, pin2)
{

}

void FuelIntakeArms::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void FuelIntakeArms::ArmExtend() {
	arms.Set(DoubleSolenoid::Value::kForward);
}

void FuelIntakeArms::ArmRetract() {
	arms.Set(DoubleSolenoid::Value::kReverse);
}

void FuelIntakeArms::Stop() {
	arms.Set(DoubleSolenoid::Value::kOff);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
