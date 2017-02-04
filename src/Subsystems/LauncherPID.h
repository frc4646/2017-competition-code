#ifndef LauncherPID_H
#define LauncherPID_H

#include <Commands/PIDSubsystem.h>
#include "PinEnums.h"
#include "WPILib.h"

class LauncherPID : public PIDSubsystem {
public:
	LauncherPID(MotorPin launcherPin, DIOPin counterPin);
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();
	void Manual();
	void SetManual(double power);

private:
	Spark& pidMotor;
	Counter& pidEncoder;

};

#endif  // LauncherPID_H
