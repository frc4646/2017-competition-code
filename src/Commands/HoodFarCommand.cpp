#include "HoodFarCommand.h"

HoodFarCommand::HoodFarCommand() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(launcherhood.get());
}

// Called just before this Command runs the first time
void HoodFarCommand::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void HoodFarCommand::Execute() {
	launcherhood->Extend();
}

// Make this return true when this Command no longer needs to run execute()
bool HoodFarCommand::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void HoodFarCommand::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void HoodFarCommand::Interrupted() {

}
