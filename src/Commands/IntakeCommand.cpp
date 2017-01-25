#include "IntakeCommand.h"
#include "WPILib.h"
#include "Subsystems/FuelIntakeRoller.h"

IntakeCommand::IntakeCommand() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(roller.get());
}

// Called just before this Command runs the first time
void IntakeCommand::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void IntakeCommand::Execute() {
	roller->SetSpeed(0.5);
}

// Make this return true when this Command no longer needs to run execute()
bool IntakeCommand::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void IntakeCommand::End() {
	roller->SetSpeed(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakeCommand::Interrupted() {
	roller->SetSpeed(0);
}
