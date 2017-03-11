#ifndef RadioShackUltrasonic_H
#define RadioShackUltrasonic_H

#include <Commands/Subsystem.h>
#include "Ultrasonic.h"
#include "Counter.h"

class RadioShackUltrasonic : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std::unique_ptr<frc::Counter> foo;
public:
	RadioShackUltrasonic(int pin);
	void InitDefaultCommand();

	double GetDistance();
	void SendSD();
};

#endif  // RadioShackUltrasonic_H
