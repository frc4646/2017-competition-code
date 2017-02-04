#include "DriveStraightTime.h"

DriveStraightTime::DriveStraightTime(double speed)
: CommandBase("DriveStraightTime")
, CommandSpeed(speed)
{
	Requires(CommandBase::drivetrain.get());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void DriveStraightTime::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void DriveStraightTime::Execute() {
	drivetrain->StraightDrive(CommandSpeed);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveStraightTime::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DriveStraightTime::End() {
drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveStraightTime::Interrupted() {
	drivetrain->Stop();
}
