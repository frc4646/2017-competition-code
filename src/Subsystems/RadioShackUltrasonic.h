#ifndef RadioShackUltrasonic_H
#define RadioShackUltrasonic_H

#include <Commands/Subsystem.h>

class RadioShackUltrasonic : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:
	RadioShackUltrasonic();
	void InitDefaultCommand();
};

#endif  // RadioShackUltrasonic_H
