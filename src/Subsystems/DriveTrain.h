#ifndef DriveTrain_H
#define DriveTrain_H

#include "WPILib.h"
#include "PinEnums.h"
#include "Spark.h"

#include <Commands/Subsystem.h>

class DriveTrain : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	Spark leftMotors;
	Spark rightMotors;
	RobotDrive InlineDrive;

public:
	DriveTrain(MotorPin left, MotorPin right);
	void InitDefaultCommand();
	void HandleDrive(Joystick& left, Joystick& right);
	void Stop();
};

#endif  // DriveTrain_H
