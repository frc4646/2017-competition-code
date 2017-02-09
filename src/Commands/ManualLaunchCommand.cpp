#include "ManualLaunchCommand.h"
#include "WPILib.h"
#include "Subsystems/LauncherPID.h"

ManualLaunchCommand::ManualLaunchCommand(double power):
launchPower(power)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(launcher.get());
}

// Called just before this Command runs the first time
void ManualLaunchCommand::Initialize() {
	launcher->Manual();
}

// Called repeatedly when this Command is scheduled to run
void ManualLaunchCommand::Execute() {
launcher->SetManual(launchPower);
}

// Make this return true when this Command no longer needs to run execute()
bool ManualLaunchCommand::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ManualLaunchCommand::End() {
launcher->SetManual(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ManualLaunchCommand::Interrupted() {
	launcher->SetManual(0);
}
