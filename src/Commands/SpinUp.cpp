#include "SpinUp.h"

SpinUp::SpinUp(double speed)
	:launchSpeed(speed) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(launcher.get());
}

// Called just before this Command runs the first time
void SpinUp::Initialize() {
	launcher->SetSetpoint(launchSpeed);
	launcher->Enable();
}

// Called repeatedly when this Command is scheduled to run
void SpinUp::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool SpinUp::IsFinished() {
	return launcher->OnTarget();
}

// Called once after isFinished returns true
void SpinUp::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SpinUp::Interrupted() {

}
