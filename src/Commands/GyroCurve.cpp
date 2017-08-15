#include "GyroCurve.h"
#include "Subsystems/DriveTrain.h"
#include "OI.h"

GyroCurve::GyroCurve() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drivetrain.get());
}

// Called just before this Command runs the first time
void GyroCurve::Initialize() {
	drivetrain->ResetGyro();
}

// Called repeatedly when this Command is scheduled to run
void GyroCurve::Execute() {
	drivetrain->CurveGyro(-oi->GetGamepad().GetRawAxis(1), -oi->GetGamepad().GetRawAxis(0));
}

// Make this return true when this Command no longer needs to run execute()
bool GyroCurve::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void GyroCurve::End() {
	drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GyroCurve::Interrupted() {
	End();
}
