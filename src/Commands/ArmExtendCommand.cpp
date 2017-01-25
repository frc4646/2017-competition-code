#include "ArmExtendCommand.h"
#include "WPILib.h"

ArmExtendCommand::ArmExtendCommand() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(arms.get());
}

// Called just before this Command runs the first time
void ArmExtendCommand::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ArmExtendCommand::Execute() {
	arms->ArmExtend();
}

// Make this return true when this Command no longer needs to run execute()
bool ArmExtendCommand::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ArmExtendCommand::End() {
	arms->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmExtendCommand::Interrupted() {
	arms->Stop();
}
