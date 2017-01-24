#ifndef Climber_H
#define Climber_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include "PinEnums.h"
#include "Spark.h"

class Climber : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Spark climber;

public:
	Climber(MotorPin climberPin);
	void InitDefaultCommand();
	void SetSpeed(double climberSpeed);
};

#endif  // Climber_H
