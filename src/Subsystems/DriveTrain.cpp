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

void DriveTrain::HandleDrive(Joystick& left, Joystick& right) {
	InlineDrive.TankDrive(left.GetRawAxis(1)*-1.0, right.GetRawAxis(1)*-1.0);
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
	std::cout << "Robot Curve is " << gyroCurve << " Robot power is " << robotPower << std::endl;
	if (robotPower > 0) {
		SetDrive(robotPower, -gyroCurve);
	}
	else {
		SetDrive(robotPower, gyroCurve);
	}
}

double DriveTrain::GetHeading() {
	return Gyro.GetAngle();
}

void DriveTrain::ResetGyro(){
	Gyro.Reset();
}

void DriveTrain::CalibrateGyro() {
	Gyro.Calibrate();
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
