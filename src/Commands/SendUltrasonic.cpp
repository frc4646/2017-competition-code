#include "SendUltrasonic.h"

SendUltrasonic::SendUltrasonic() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(backusensor.get());
}

// Called just before this Command runs the first time
void SendUltrasonic::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void SendUltrasonic::Execute() {
	backusensor->SendSD();
}

// Make this return true when this Command no longer needs to run execute()
bool SendUltrasonic::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void SendUltrasonic::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SendUltrasonic::Interrupted() {

}
