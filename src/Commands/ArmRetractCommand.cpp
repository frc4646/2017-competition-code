#include "ArmRetractCommand.h"
#include "WPILib.h"

ArmRetractCommand::ArmRetractCommand() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(arms.get());
}

// Called just before this Command runs the first time
void ArmRetractCommand::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ArmRetractCommand::Execute() {
	arms->ArmRetract();
}

// Make this return true when this Command no longer needs to run execute()
bool ArmRetractCommand::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ArmRetractCommand::End() {
	arms->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmRetractCommand::Interrupted() {
	arms->Stop();
}
