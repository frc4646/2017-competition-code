#ifndef Indexer_H
#define Indexer_H

#include <Commands/Subsystem.h>
#include "PinEnums.h"
#include "WPILib.h"

class Indexer : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Spark index;

public:
	Indexer(MotorPin indexerPin);
	void InitDefaultCommand();
	void SetSpeed(double power);
};

#endif  // Indexer_H
