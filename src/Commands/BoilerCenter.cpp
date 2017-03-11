#include "BoilerCenter.h"
#include "Subsystems/BoilerVisionCalculation.h"
#include "Subsystems/BoilerAnglePIDSource.h"
#include "Subsystems/DriveTrain.h"
#include "CommandBase.h"
#include <algorithm>

BoilerCenter::BoilerCenter():
CommandBase("BoilerCenter"),
turning(0),
robotTurn(0),
confidence(0),
po(),
ps(boilervisioncalculation.get()),
pc(0.5,0,0,&ps,&po, 0.05)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	SmartDashboard::PutData("BoilerCenter", &pc);
	Requires(boilervisioncalculation.get());
	Requires(drivetrain.get());
	LiveWindow::GetInstance()->AddActuator("BiolerPID", "Align", pc);
}

// Called just before this Command runs the first time
void BoilerCenter::Initialize() {
	pc.Reset();
	pc.SetSetpoint(0.0);
	pc.SetOutputRange(-0.3, 0.3);
	pc.SetAbsoluteTolerance(0.01);
	pc.Enable();
}

// Called repeatedly when this Command is scheduled to run
void BoilerCenter::Execute() {
	robotTurn = pc.Get();
	const float deadband = 0.25;

	if(robotTurn > 0)
	{
		robotTurn += deadband;
	}
	if(robotTurn < 0)
	{
		robotTurn -= deadband;
	}
	SmartDashboard::PutNumber("BoilerCenterOutput", robotTurn);
	drivetrain->SetDrive(robotTurn, 1);
}

// Make this return true when this Command no longer needs to run execute()
bool BoilerCenter::IsFinished() {
	return pc.OnTarget();
}

// Called once after isFinished returns true
void BoilerCenter::End() {
	drivetrain->SetDrive(0,0);
	pc.Disable();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BoilerCenter::Interrupted() {
	End();
}
