#ifndef PressureSensor_H
#define PressureSensor_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include "PinEnums.h"

class PressureSensor : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std::unique_ptr<AnalogInput> PSensor;
	std::shared_ptr<NetworkTable> networkTable;

public:
	PressureSensor(AnalogPin PPin);
	void InitDefaultCommand();
	double GetVoltage();
	double GetPressure();
	void SendSD();
};

#endif  // PressureSensor_H
