#include <Commands/DriveUntilFarBack.h>

DriveUntilFarBack::DriveUntilFarBack(double power, double distance):
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
void DriveUntilFarBack::Initialize() {
	confidence = 0;
}

// Called repeatedly when this Command is scheduled to run
void DriveUntilFarBack::Execute() {
	drivetrain->StraightDrive(drivePower);
	SmartDashboard::PutNumber("Ultrasonic",backusensor->GetDistance());
	if(backusensor->GetDistance() > targetDistance){
		confidence++;
			}
}

// Make this return true when this Command no longer needs to run execute()
bool DriveUntilFarBack::IsFinished() {
	return confidence >= 3;
}

// Called once after isFinished returns true
void DriveUntilFarBack::End() {
	drivetrain->SetDrive(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveUntilFarBack::Interrupted() {
	End();
}
