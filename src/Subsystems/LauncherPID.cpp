#include "LauncherPID.h"

#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SmartDashboard.h>

#include "../RobotMap.h"

LauncherPID::LauncherPID(MotorPin launcherPin, DIOPin counterPin) :
PIDSubsystem("LauncherPID", 1.0, 0.0, 0.0),
pidMotor(launcherPin),
pidEncoder(counterPin)
{
	// Use these to get going:
	// SetSetpoint() -  Sets where the PID controller should move the system
	//                  to
	// Enable() - Enables the PID controller.
	SetOutputRange(0,1);
	SetAbsoluteTolerance(.05);
	SetPIDSourceType(PIDSourceType::kDisplacement);
	pidEncoder.SetSamplesToAverage(1);
}

double LauncherPID::ReturnPIDInput() {
	// Return your input value for the PID loop
	// e.g. a sensor, like a potentiometer:
	// yourPot->SetAverageVoltage() / kYourMaxVoltage;
	double speed = (1.0/(pidEncoder.GetPeriod()))*60.0;
	return speed/5000;
}

void LauncherPID::UsePIDOutput(double output) {
	// Use output to drive your system, like a motor
	// e.g. yourMotor->Set(output);
	pidMotor.PIDWrite(output);
}

void LauncherPID::Manual()
{
	Disable();

}

void LauncherPID::SetManual(double power)
{
	pidMotor.Set(power);
}

void LauncherPID::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}
