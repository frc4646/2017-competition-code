#include "RadioShackUltrasonic.h"
#include "../RobotMap.h"
#include "Commands/SendUltrasonic.h"

#include <unistd.h>

RadioShackUltrasonic::RadioShackUltrasonic(DIOPin Upin) :
frc::Subsystem("ExampleSubsystem"),
//USensor(Upin,Upin2)
cou(Upin)
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
			//*62500;

}

void RadioShackUltrasonic::SendSD() {
	SmartDashboard::PutNumber("UltrasonicDistance", GetDistance());
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
