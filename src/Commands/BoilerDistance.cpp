#include "BoilerDistance.h"
#include "Subsystems/BoilerVisionCalculation.h"
#include "Subsystems/BoilerDistancePIDSource.h"
#include "Subsystems/DriveTrain.h"
#include "CommandBase.h"
#include <algorithm>

BoilerDistance::BoilerDistance():
CommandBase("BoilerDistance"),
distancePower(0),
confidence(0),
po(),
ps(boilervisioncalculation.get()),
pc(0,0,0,&ps,&po, 0.05){
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	SmartDashboard::PutData("BoilerDistance", &pc);
	Requires(boilervisioncalculation.get());
	Requires(drivetrain.get());
	LiveWindow::GetInstance()->AddActuator("BoilerPID", "Dist", pc);
}

// Called just before this Command runs the first time
void BoilerDistance::Initialize() {
	pc.Reset();
	pc.SetSetpoint(0.0);
	pc.SetOutputRange(-0.3, 0.3);
	pc.SetAbsoluteTolerance(0.01);
	pc.Enable();
	drivetrain->ResetGyro();
}

// Called repeatedly when this Command is scheduled to run
void BoilerDistance::Execute() {
	distancePower = pc.Get();
	drivetrain->StraightDrive(distancePower);
}

// Make this return true when this Command no longer needs to run execute()
bool BoilerDistance::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void BoilerDistance::End() {
	drivetrain->StraightDrive(0);
	pc.Disable();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BoilerDistance::Interrupted() {
	End();
}
