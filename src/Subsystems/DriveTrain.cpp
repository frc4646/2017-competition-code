#include "DriveTrain.h"
#include "../RobotMap.h"
#include "Commands/TankDrive.h"

DriveTrain::DriveTrain(MotorPin left, MotorPin right) :
	Subsystem("DriveTrain"),
	leftMotors(left),
	rightMotors(right),
	InlineDrive(leftMotors, rightMotors),
//	Gyro(0)
	Gyro()
{
	Gyro.Calibrate();
//	leftMotors.SetInverted(true);
//	rightMotors.SetInverted(true);
}

void DriveTrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new TankDrive());
	InlineDrive.SetSafetyEnabled(false);
}

void DriveTrain::HandleDrive(Joystick& gamepad) {
	if (gamepad.GetRawButton(2)) {
		InlineDrive.TankDrive(gamepad.GetRawAxis(1)*-1.0, gamepad.GetRawAxis(5)*-1.0);
	} else {
		InlineDrive.TankDrive(gamepad.GetRawAxis(1)*-0.85, gamepad.GetRawAxis(5)*-0.85);
	}
}

void DriveTrain::Stop() {
	leftMotors.SetSpeed(0);
	rightMotors.SetSpeed(0);
}

void DriveTrain::SetDrive(double power, double curve) {
	InlineDrive.Drive(power, curve);
}

void DriveTrain::StraightDrive(double power) {
	double gyroCurve = GetHeading()/90.0;
	double robotPower = power;
	if (robotPower > 0) {
		SetDrive(robotPower, -gyroCurve);
	}
	else {
		SetDrive(robotPower, gyroCurve);
	}
}

void DriveTrain::CurveGyro(double power, double curve) {
	double gyroCurve = GetHeading()/90.0;
	double robotPower = power;
	if (robotPower > 0) {
		SetDrive(robotPower, -(gyroCurve + curve));
	}
	else {
		SetDrive(robotPower, gyroCurve + curve);
	}
}

double DriveTrain::GetHeading() {
	return -Gyro.GetAngle();
}

void DriveTrain::ResetGyro(){
	Gyro.Reset();
}

void DriveTrain::CalibrateGyro() {
	Gyro.Calibrate();
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
