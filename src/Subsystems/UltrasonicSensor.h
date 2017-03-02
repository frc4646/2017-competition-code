#ifndef UltrasonicSensor_H
#define UltrasonicSensor_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include "PinEnums.h"

class UltrasonicSensor : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std::unique_ptr<AnalogInput> USensor;
	std::shared_ptr<NetworkTable> networkTable;

public:
	UltrasonicSensor(AnalogPin UPin);
	void InitDefaultCommand();
	double GetVoltage();
	double GetDistance();
	void SendSD();
};

#endif  // UltrasonicSensor_H
