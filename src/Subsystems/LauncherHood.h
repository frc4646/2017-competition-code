#ifndef LauncherHood_H
#define LauncherHood_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include "PinEnums.h"

class LauncherHood : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Solenoid piston;

public:
	LauncherHood(SolenoidPin pin);
	void InitDefaultCommand();
	void Far();
	void Close();
};

#endif  // LauncherHood_H
