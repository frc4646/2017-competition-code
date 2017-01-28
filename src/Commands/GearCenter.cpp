#include "GearCenter.h"
#include "Subsystems/GearVisionCalculation.h"
#include "Subsystems/GearAnglePIDSource.h"
#include "Subsystems/DriveTrain.h"
#include "CommandBase.h"
#include <algorithm>

GearCenter::GearCenter():
CommandBase("GearCenter"),
turning(0),
robotTurn(0),
confidence(0),
po(),
ps(gearvisioncalculation.get()),
pc(0.0,0,0,&ps,&po)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	SmartDashboard::PutData("GearCenter", &pc);
	Requires(gearvisioncalculation.get());
	Requires(drivetrain.get());
}

// Called just before this Command runs the first time
void GearCenter::Initialize() {
	pc.Reset();
	pc.SetSetpoint(0.0);
	pc.SetOutputRange(-0.0, 0.0);
	pc.Enable();
}

// Called repeatedly when this Command is scheduled to run
void GearCenter::Execute() {
	robotTurn = pc.Get();
	const float deadband = 0.0;
}

// Make this return true when this Command no longer needs to run execute()
bool GearCenter::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void GearCenter::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GearCenter::Interrupted() {

}
