#include "SetDriveCommand.h"

SetDriveCommand::SetDriveCommand(double power, double curve):
p(power),
c(curve)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drivetrain.get());
}

// Called just before this Command runs the first time
void SetDriveCommand::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void SetDriveCommand::Execute() {
	drivetrain->SetDrive(p,c);
}

// Make this return true when this Command no longer needs to run execute()
bool SetDriveCommand::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void SetDriveCommand::End() {
	drivetrain->SetDrive(0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetDriveCommand::Interrupted() {
	End();
}
