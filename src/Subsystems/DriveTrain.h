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
	ADXRS450_Gyro Gyro;
//	AnalogGyro Gyro;
public:
	DriveTrain(MotorPin left, MotorPin right);
	void InitDefaultCommand();
	void HandleDrive(Joystick& gamepad);
	void Stop();
	void SetDrive(double power, double curve);
	void StraightDrive(double power);
	void CurveGyro(double power, double curve);
	double GetHeading();
	void ResetGyro();
	void CalibrateGyro();

};

#endif  // DriveTrain_H
