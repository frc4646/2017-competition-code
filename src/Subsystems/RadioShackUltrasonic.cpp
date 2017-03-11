#include "RadioShackUltrasonic.h"
#include "../RobotMap.h"
#include "Commands/SendUltrasonic.h"

#include <unistd.h>

RadioShackUltrasonic::RadioShackUltrasonic(DIOPin Upin, DIOPin Upin2) :
frc::Subsystem("ExampleSubsystem"),
//USensor(Upin,Upin2)
dio(Upin),
cou(Upin2)
{
//	USensor.SetAutomaticMode(true);
	networkTable = NetworkTable::GetTable("ultrasonic");
	cou.SetSemiPeriodMode(true);
	cou.SetMaxPeriod(1.0);
}

void RadioShackUltrasonic::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new SendUltrasonic());
}

double RadioShackUltrasonic::GetDistance() {
//	return USensor.GetRangeInches();

//	dio.Set(false);
//	usleep(2);
//	dio.Set(true);
//	usleep(5);
//	dio.Set(false);
//	cou.Reset();
//
////	usleep(100);
//	while(true)
//	{
//		std::cout << cou.GetPeriod() << std::endl;
//	}
	return cou.GetPeriod();

}

void RadioShackUltrasonic::SendSD() {
	SmartDashboard::PutNumber("UltrasonicDistance", GetDistance());
	std::cout << "Ultrasonic sending " << GetDistance() << std::endl;
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
