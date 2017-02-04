#include "Index.h"
#include "WPILib.h"
#include "Subsystems/Index.h"

Index::Index(double power):
indexPower(power)
{
		// Use Requires() here to declare subsystem dependencies
		// eg. Requires(Robot::chassis.get());
		Requires(indexer.get());
}

// Called just before this Command runs the first time
void Index::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void Index::Execute() {
	indexer->SetSpeed(indexPower);
}

// Make this return true when this Command no longer needs to run execute()
bool Index::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void Index::End() {
	indexer->SetSpeed(0);

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Index::Interrupted() {
	indexer->SetSpeed(0);

}
