#include "DoNothingAuto.h"

DoNothingAuto::DoNothingAuto() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void DoNothingAuto::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void DoNothingAuto::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool DoNothingAuto::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void DoNothingAuto::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DoNothingAuto::Interrupted() {

}
