#include "LauncherHood.h"
#include "../RobotMap.h"

LauncherHood::LauncherHood(SolenoidPin pin) : Subsystem("ExampleSubsystem"),
piston(pin) {

}

void LauncherHood::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void LauncherHood::Extend() {
	piston.Set(true);
}

void LauncherHood::Retract() {
	piston.Set(false);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
