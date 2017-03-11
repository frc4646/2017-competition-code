#ifndef RadioShackUltrasonic_H
#define RadioShackUltrasonic_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include "PinEnums.h"

class RadioShackUltrasonic : public frc::Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
//	Ultrasonic USensor;
	DigitalOutput dio;
	Counter cou;
	std::shared_ptr<NetworkTable> networkTable;
public:
	RadioShackUltrasonic(DIOPin Upin, DIOPin Upin2);
	void InitDefaultCommand();
	double GetDistance();
	void SendSD();
};
#endif  // RADIOSHACKULTRASONIC_H
