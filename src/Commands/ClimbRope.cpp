#include "ClimbRope.h"
#include "WPILib.h"

ClimbRope::ClimbRope() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(climber.get());
}

// Called just before this Command runs the first time
void ClimbRope::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ClimbRope::Execute() {
	climber->SetSpeed(.5);
}

// Make this return true when this Command no longer needs to run execute()
bool ClimbRope::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ClimbRope::End() {
climber->SetSpeed(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ClimbRope::Interrupted() {
	climber->SetSpeed(0);
}
