#include "DriveStraightGamepad.h"
#include "Subsystems/DriveTrain.h"
#include "OI.h"

DriveStraightGamepad::DriveStraightGamepad()
: CommandBase("DriveStraightGamepad") {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drivetrain.get());
}

// Called just before this Command runs the first time
void DriveStraightGamepad::Initialize() {
	drivetrain->ResetGyro();
}

// Called repeatedly when this Command is scheduled to run
void DriveStraightGamepad::Execute() {
	double power = oi->GetGamepad().GetRawAxis(1)*-0.85;
	drivetrain->StraightDrive(power);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveStraightGamepad::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DriveStraightGamepad::End() {
	drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveStraightGamepad::Interrupted() {
	End();
}
