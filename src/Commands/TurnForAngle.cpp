#include "TurnForAngle.h"
#include "Subsystems/DriveTrain.h"
#include <math.h>


TurnForAngle::TurnForAngle(double robotPower, double angle):
power(robotPower),
angle(angle)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drivetrain.get());

}

// Called just before this Command runs the first time
void TurnForAngle::Initialize() {
	initDif = abs(drivetrain->GetHeading()-angle);
}

// Called repeatedly when this Command is scheduled to run
void TurnForAngle::Execute() {
	drive = power* abs(drivetrain->GetHeading()-angle)/initDif;
	if (drive < .3)
	{
		drive = .3;
	}

	if(drive > 0.5)
	{
		drive = 0.5;
	}

	if (angle > 0)
	{
		drivetrain->SetDrive(drive, 1);
	}
	else
	{
		drivetrain->SetDrive(drive, -1);
	}

}

// Make this return true when this Command no longer needs to run execute()
bool TurnForAngle::IsFinished() {
	error = drivetrain->GetHeading() - angle;
	if (angle > 0){
		error = -error;
	}
	return error < 0;
}

// Called once after isFinished returns true
void TurnForAngle::End() {
	drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TurnForAngle::Interrupted() {
	End();
}
