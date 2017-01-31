#include "DriveUntilDistance.h"
#include "WPILib.h"

DriveUntilDistance::DriveUntilDistance(double power, double distance):
targetDistance(distance),
drivePower(power),
confidence(0)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drivetrain.get());
	Requires(backusensor.get());
}

// Called just before this Command runs the first time
void DriveUntilDistance::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void DriveUntilDistance::Execute() {
	drivetrain->StraightDrive(drivePower);
	SmartDashboard::PutNumber("Ultrasonic",backusensor->GetDistance());
	if(backusensor->GetDistance() < targetDistance){
		confidence++;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool DriveUntilDistance::IsFinished() {
	return confidence >= 3;
}

// Called once after isFinished returns true
void DriveUntilDistance::End() {
	drivetrain->SetDrive(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveUntilDistance::Interrupted() {
	End();
}
