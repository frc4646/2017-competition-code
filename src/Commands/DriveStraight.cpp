#include "DriveStraight.h"
#include "Subsystems/DriveTrain.h"
#include "OI.h"

DriveStraight::DriveStraight()
: CommandBase("DriveStraight")
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drivetrain.get());
}

// Called just before this Command runs the first time
void DriveStraight::Initialize() {
	drivetrain->ResetGyro();
}

// Called repeatedly when this Command is scheduled to run
void DriveStraight::Execute() {
	double robotPower = -oi->GetRightStick().GetRawAxis(1);
	drivetrain->StraightDrive(robotPower);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveStraight::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DriveStraight::End() {
	drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveStraight::Interrupted() {
	End();
}
