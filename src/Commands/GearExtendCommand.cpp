#include "GearExtendCommand.h"
#include "WPILib.h"

GearExtendCommand::GearExtendCommand() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(gearpneumatic.get());
}

// Called just before this Command runs the first time
void GearExtendCommand::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void GearExtendCommand::Execute() {
	gearpneumatic->GearExtend();
}

// Make this return true when this Command no longer needs to run execute()
bool GearExtendCommand::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void GearExtendCommand::End() {
	gearpneumatic->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GearExtendCommand::Interrupted() {
	gearpneumatic->Stop();
}
