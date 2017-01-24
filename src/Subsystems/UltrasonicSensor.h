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

public:
	UltrasonicSensor(AnalogPin UPin);
	void InitDefaultCommand();
	double GetVoltage();
	double GetDistance();
};

#endif  // UltrasonicSensor_H
