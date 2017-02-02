#include "GearRetractCommand.h"
#include "WPILib.h"

GearRetractCommand::GearRetractCommand() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(gearpneumatic.get());
}

// Called just before this Command runs the first time
void GearRetractCommand::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void GearRetractCommand::Execute() {
	gearpneumatic->GearRetract();
}

// Make this return true when this Command no longer needs to run execute()
bool GearRetractCommand::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void GearRetractCommand::End() {
	gearpneumatic->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GearRetractCommand::Interrupted() {
	gearpneumatic->Stop();
}
