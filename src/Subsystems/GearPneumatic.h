#ifndef GearPneumatic_H
#define GearPneumatic_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include "PinEnums.h"
#include "DoubleSolenoid.h"

class GearPneumatic : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	DoubleSolenoid gearArms;

public:
	GearPneumatic(SolenoidPin pin1, SolenoidPin pin2);
	void InitDefaultCommand();
	void GearExtend();
	void GearRetract();
	void Stop();
};

#endif  // GearPneumatic_H
