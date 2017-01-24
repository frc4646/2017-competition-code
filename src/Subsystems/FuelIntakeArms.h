#ifndef FuelIntakeArms_H
#define FuelIntakeArms_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include "PinEnums.h"
#include "DoubleSolenoid.h"

class FuelIntakeArms : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	DoubleSolenoid arms;

public:
	FuelIntakeArms(SolenoidPin pin1, SolenoidPin pin2);
	void InitDefaultCommand();
	void ArmExtend();
	void ArmRetract();
	void Stop();
};

#endif  // FuelIntakeArms_H
