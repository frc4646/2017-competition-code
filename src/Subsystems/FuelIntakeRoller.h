#ifndef FuelIntakeRoller_H
#define FuelIntakeRoller_H

#include "WPILib.h"
#include "Spark.h"
#include "PinEnums.h"
#include <Commands/Subsystem.h>

class FuelIntakeRoller : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Spark roller;

public:
	FuelIntakeRoller(MotorPin rollerPin);
	void InitDefaultCommand();
	void SetSpeed(double speed);
};

#endif  // FuelIntakeRoller_H
